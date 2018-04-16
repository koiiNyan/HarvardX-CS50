#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    //Prompting for credit card number

    long long cc_number;
    do
    {
        cc_number = get_long_long("Number: ");
    }
    while (cc_number <= 0);

    // Finding the length of the cc number
    int length = 0;
    long long num = cc_number;
    while (num != 0)
    {
        length++;
        num = num / 10;
    }

    int sum_of_digits = 0;

    // Multiply every other digit by 2, starting from the 2nd last digit. Take the result and sum the digits.
    // Add all the sums of the products' digits together
    for (int i = 2; i < length + 2; i += 2)
    {
        long long point = pow(10, i); //funt pow - returns i raised to the power of 10
        int current_num = (cc_number % point) / (point / 10);
        int product = current_num * 2; //multiplying every other digit
        sum_of_digits += product / 10 + product % 10;
    }
    // Add every other digit to the total sum of digits, starting from the last digit.
    for (int i = 1; i <= length; i += 2)
    {
        long long point = pow(10, i);
        int current_num = (cc_number % point) / (point / 10);
        sum_of_digits += current_num;
    }

    // Check if the sum of the digits is divisible by 10.
    if (sum_of_digits % 10 == 0)
    {
        //Validating company's ID
        //AMEX - 15 numbers starting with 34, 37
        if (cc_number >= 340000000000000 && cc_number <= 349999999999999)
        {
            printf("AMEX\n");
        }
        else if (cc_number >= 370000000000000 && cc_number <= 379999999999999)

        {
            printf("AMEX\n");
        }

        //MASTERCARDO - 16 nums st with 51/52/53/54/55
        else if (cc_number >= 5100000000000000 && cc_number <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        //VISA - 13 or 16 nums st with 4
        else if (cc_number >= 4000000000000 && cc_number <= 4999999999999)
        {
            printf("VISA\n");
        }
        else if (cc_number >= 4000000000000000 && cc_number <= 4999999999999999)

        {
            printf("VISA\n");
        }

        //INVALID
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

