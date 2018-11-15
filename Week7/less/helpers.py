from nltk.tokenize import sent_tokenize

def lines(a, b):
    """Return lines in both a and b"""

    # TODO

    # Take in string inputs a, b
    # Split each string into lines
    # Compute a list of all lines that appear in both a and b
    # Data structures to consider to keep track of which lines are present in both
    # Avoid duplicates
    # Return list should be a list of all the lines that the two files have in common,
    # but each one of common lines should appear once at maximum

    # Splitting lines into list items (lines)
    a_list = a.split('\n')
    b_list = b.split('\n')
    similar_lines = []


    for line in a_list:
        if line in b_list:
            similar_lines.append(line)

    # Reducing duplicates
    similar_lines = list(dict.fromkeys(similar_lines))
    return similar_lines




def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    # Take in string inputs a, b
    # Split each string into sentences
    # Compute list of all sentences appearing in both a and b
    # NLTK library

    # Splitting lines into list items (sentences)
    a_sentences = sent_tokenize(a)
    b_sentences = sent_tokenize(b)
    similar_sentences = []

    for sentence in a_sentences:
        if sentence in b_sentences:
            similar_sentences.append(sentence)


    # Reducing duplicates
    similar_sentences = list(dict.fromkeys(similar_sentences))
    return similar_sentences


# Helper function for substrings
def split_time(string, length):
    splitted_list = []
    for i in range(0,len(string)):
        if len(string[i:length+i]) == length:
            splitted_list.append(string[i:length+i])
    return splitted_list



def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    # Take in string inputs a, b, and substring length n
    # Split each string into all substrings of length n
    # Compute list of all sentences appearing in both a and b

    ### Extract substrings from string
    #   s[i:j]
    #   Helper function:
    #   Take a string and get all of the substrings of a particular length

    list_a = split_time(a,n)
    list_b = split_time(b,n)

    similar_substrings = []

    for substring in list_a:
        if substring in list_b:
            similar_substrings.append(substring)


    similar_substrings = list(dict.fromkeys(similar_substrings))
    return similar_substrings
