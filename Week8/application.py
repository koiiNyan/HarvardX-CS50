import os


from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime
# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    """Show portfolio of stocks"""

    if request.method == "POST":
        """Adds cash to user's current cash if everything is OK"""

        # Checks if user entered symbol
        if not request.form.get("add_cash"):
            return apology("must provide cash")

        # Checks if user entered a digit
        if not request.form.get("add_cash").isdigit():
            return apology("only digits supported")


        # Query to add cash
        cash_to_add = int(request.form.get("add_cash"))

        db.execute("UPDATE users SET cash = cash + :cash_to_add WHERE id = :user_id",
            user_id=session["user_id"], cash_to_add=cash_to_add)

        return redirect("/")




    # Query returns a list with a dict
    user_cash_query = db.execute("SELECT cash FROM users WHERE id = :user_id",
                      user_id=session["user_id"])

    # Formats user's cash as float
    user_cash = float(user_cash_query[0]['cash'])


    # Query for current amount of stoks
    current_stocks = db.execute("SELECT symbol, amount FROM current WHERE user_id = :user_id",
                      user_id=session["user_id"])


     # Empty lists to work with
    symbols = []
    amount = []
    names = []
    curr_price_each = []
    total_curr_price = []


    # Appending stocks and amounts to lists
    for counter in range(0, len(current_stocks)):
        symbols.append(current_stocks[counter]['symbol'])
        amount.append(current_stocks[counter]['amount'])

    # Looking up for current price of each stock
    for symbol in symbols:
        quote = lookup(symbol)
        price = quote['price']
        name = quote['name']
        curr_price_each.append(price)
        names.append(name)

    # Counting the total price of stocks
    for counter in range(0, len(amount)):
        total_curr_price.append(float(amount[counter]) * float(curr_price_each[counter]))

    # User total balance in usd
    total_balance = usd(sum(total_curr_price) + user_cash)

    # Formats user's cash as usd
    user_cash = usd(user_cash)


    return render_template("index.html", names=names,user_cash=user_cash, symbols=symbols,
                        amount=amount, curr_each=curr_price_each, curr_tot=total_curr_price, tot_bal=total_balance)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        # Checks if user entered symbol
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        # Checks if user entered shares
        if not request.form.get("shares"):
            return apology("must provide shares")

        # Getting a number of shares
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("shares must be a positive integer")

        # Checking if shares is a positive number
        if shares <= 0:
            return apology("shares must be a positive integer")

        # Getting symbol
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol")



        # Getting a company name from JSON response and storing it in a db, ignore if symbol already exists
        name = quote['name']

        db.execute("INSERT OR IGNORE INTO symbols ('symbol', 'name') VALUES(:symbol, :name)",
                  symbol=symbol, name=name)


        # Getting a float number from JSON response (cost of one share of symbol)
        price = float(quote['price'])



        # Check the final price of shares
        price_of_shares = price * shares


        # Checks DB if user has enough cash to buy

        # Query returns a list with a dict
        user_cash_query = db.execute("SELECT cash FROM users WHERE id = :user_id",
                          user_id=session["user_id"])

        # Getting a float number of user's cash from query
        user_cash = float(user_cash_query[0]['cash'])

        # Ensures that user has enough cash to buy shares
        if user_cash < price_of_shares:
            return apology("not enough cash")

        # Checks how much money there's left after user buys shares
        cash_left = user_cash - price_of_shares


        # Query for DB to store WHEN and WHAT was actually bought + amount (who, what symbol, amount, cost, date)

        # Checking username
        # Query returns a list with a dict
        username_query = db.execute("SELECT username FROM users WHERE id = :user_id",
                          user_id=session["user_id"])

        # Getting a username for future query
        username = (username_query[0]['username'])

        # Storing shares in a different table
        db.execute("INSERT INTO purchased ('user_id', 'symbol', 'amount', 'price', 'date') VALUES(:user_id, :symbol, :amount, :price, :date)",
                          user_id=session["user_id"], symbol=symbol, amount=shares, price=price_of_shares,date=datetime.now())

        # Storing data in current table, update if symbols already exist
        if not db.execute("INSERT INTO current ('user_id', 'symbol', 'amount') VALUES(:user_id, :symbol, :amount)",
                  user_id=session["user_id"], symbol=symbol, amount=shares):

            db.execute("UPDATE current SET amount = amount + :amount WHERE user_id = :user_id AND symbol = :symbol",
                      user_id=session["user_id"], symbol=symbol, amount=shares)


        # Query to delete cash from user
        db.execute("UPDATE users SET cash = :cash_left WHERE id = :user_id",
                          user_id=session["user_id"], cash_left=cash_left)

        return redirect("/")

    # If visited buy via GET (without posting anything)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # Query for joining 2 DBs
    # Doing so because full outer join is not supported
    query_purchased = db.execute("SELECT * FROM purchased WHERE user_id = :user_id ORDER BY date DESC",
                                    user_id=session["user_id"])
    query_sold = db.execute("SELECT * FROM sold WHERE user_id = :user_id ORDER BY date DESC",
                                    user_id=session["user_id"])

   # Declaring vars

    symbols = []
    amount = []
    price = []
    date = []
    action = []


    # Appending everything to lists for future rendering
    for counter in range(0, len(query_purchased)):
        symbols.append(query_purchased[counter]['symbol'])
        amount.append(query_purchased[counter]['amount'])
        # Formatting price, using float instead of int to de more accurate
        price.append(float(query_purchased[counter]['price']))
        date.append(query_purchased[counter]['date'])
        action.append(query_purchased[counter]['action'])

    for counter in range(0, len(query_sold)):
        symbols.append(query_sold[counter]['symbol'])
        amount.append(query_sold[counter]['amount'])
        # Formatting price, using float instead of int to de more accurate
        price.append(float(query_sold[counter]['price']))
        date.append(query_sold[counter]['date'])
        action.append(query_sold[counter]['action'])

    # return render_template("history.html")
    return render_template("history.html", symbols=symbols,amount=amount,price=price,date=date,action=action)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # If user submitted a form
    if request.method == "POST":

        # Checks if user provided a symbol
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        # Getting symbol variable
        symbol = request.form.get("symbol")
        quote = lookup(symbol)
        if not quote:
            return apology("invalid symbol")

        # Name and price from JSON response
        name = quote['name']
        price = usd(quote['price'])

        return render_template("quoted.html", symbol=symbol, name=name, price=price)

    else:
        # If user visited quote via GET
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
        # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username")

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password")

        # Confirmation field for pass is not blank
        elif not request.form.get("confirmation"):
            return apology("must provide password 2nd time")

        # Passwords don't match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords don't match")

        # Check if there are nums and chars in pass
        elif not any(char.isdigit() for char in request.form.get("password")) or not any(char.isalpha() for char in request.form.get("password")):
            return apology("password must have chars and digits")

        # Check for appropriate length
        elif len(request.form.get("password")) < 5:
            return apology("password must be 5 char length min")


        # Add users to DB
        result = db.execute("INSERT INTO users ('username', 'hash') VALUES(:username, :hashpw)",
                          username=request.form.get("username"), hashpw=generate_password_hash(request.form.get("password")))
        if not result:
            return apology("username already taken")


        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        # Checks if user entered symbol
        if not request.form.get("symbol"):
            return apology("must provide symbol")

        # Query for amount
        amount_q = db.execute("SELECT amount FROM purchased WHERE user_id = :user_id AND symbol = :symbol",
              user_id=session["user_id"], symbol=request.form.get("symbol"))

        # Variables
        symbol = request.form.get("symbol")
        amount_to_sell = int(request.form.get("shares"))

        # Checking the amount of purchased stocks to ensure that user can afford to sell stock(or there're not enough stocks)
        amount_purchased = 0

        for counter in range(0, len(amount_q)):
            amount_purchased += int((amount_q[counter]['amount']))

        # If not enough stocks, return apology
        if amount_purchased < amount_to_sell:
            return apology("not enough stocks")

        # Lookup for a current cost
        cost_of_one = float(lookup(symbol)['price'])
        cost_of_stocks = cost_of_one * amount_to_sell


        # Storing shares in a different table
        db.execute("INSERT INTO sold ('user_id', 'symbol', 'amount', 'price', 'date') VALUES(:user_id, :symbol, :amount, :price, :date)",
                          user_id=session["user_id"], symbol=symbol, amount=amount_to_sell, price=cost_of_stocks,date=datetime.now())


        # Updatin amount of current stock

        db.execute("UPDATE current SET amount = amount - :amount WHERE user_id = :user_id AND symbol = :symbol",
                          user_id=session["user_id"], symbol=symbol, amount=amount_to_sell)


         # Query returns a list with a dict
        user_cash_query = db.execute("SELECT cash FROM users WHERE id = :user_id",
                          user_id=session["user_id"])

        # Getting a float number of user's cash from query
        user_cash = float(user_cash_query[0]['cash'])

        # Calculate cash left
        cash_left = user_cash + cost_of_stocks
        # Query to add cash to user
        db.execute("UPDATE users SET cash = :cash_left WHERE id = :user_id",
                          user_id=session["user_id"], cash_left=cash_left)

        return redirect("/")

    # If visited buy via GET (without posting anything)
    else:


        # Query for symbols and amounts of stock
        symb_q = db.execute("SELECT symbol FROM purchased WHERE user_id = :user_id",
                      user_id=session["user_id"])


        # Declaring vars

        symbols = []


        # Appending stocks to list
        for counter in range(0, len(symb_q)):
            symbols.append(symb_q[counter]['symbol'])

        # Reducing duplicates
        symbols = list(dict.fromkeys(symbols))



        return render_template("sell.html", symbols=symbols)


@app.route("/changepwd", methods=["GET", "POST"])
@login_required
def changepwd():
    """Allows user to change password."""

    if request.method == "POST":

        # Ensure password was submitted
        if not request.form.get("password"):
            return apology("must provide password")

        # Confirmation field for pass is not blank
        elif not request.form.get("confirmation"):
            return apology("must provide password 2nd time")

        # Passwords don't match
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords don't match")

        # Check if there are nums and chars in pass
        elif not any(char.isdigit() for char in request.form.get("password")) or not any(char.isalpha() for char in request.form.get("password")):
            return apology("password must have chars and digits")

        # Check for appropriate length
        elif len(request.form.get("password")) < 5:
            return apology("password must be 5 char length min")

        # Query to update password
        db.execute("UPDATE users SET hash = :hashpw WHERE id = :user_id",
                          user_id=session["user_id"], hashpw=generate_password_hash(request.form.get("password")))

        return redirect("/")

    # User reached route via GET (as by clicking a link)
    else:
        return render_template("changepwd.html")





def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
