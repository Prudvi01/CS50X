import nltk


# METHOD TO FIND THE COMMON ELEMENTS FROM THE GIVEN INPUTS
def common(a, b):
    common_list = []
    a = list(a)
    b = list(b)
    for i, element in enumerate(a):
        for ele in b:
            if element == ele:
                common_list.append(a[i])

    return (set(common_list))


# METHOD TO RETURN A LIST OF SUBSTRINGS OF LENGTH n FROM THE GIVEN STRING
def sub_string(a, n):
    sub_string_list = []
    for i in range(0, len(a) - n + 1):
        sub_string_list.append(a[i:n + i])

    return sub_string_list


# METHOD TO SPLIT THE GIVEN STRING INPUT FILES INTO LINES AND COMPARE THE COMMON LINES FROM THE BOTH
def lines(a, b):
    """Return lines in both a and b"""
    lines_a = a.splitlines()
    lines_b = b.splitlines()
    return common(lines_a, lines_b)


# METHOD TO SPLIT THE GIVEN STRING INPUT FILES INTO SENTENCES AND COMPARE THE COMMON SENTENCES FROM THE BOTH
def sentences(a, b):
    """Return sentences in both a and b"""
    a_sent = nltk.sent_tokenize(a)
    b_sent = nltk.sent_tokenize(b)
    return common(a_sent, b_sent)


# METHOD TO SPLIT THE GIVEN STRING INPUT FILES INTO SUBSTRINGS OF LENGTH n AND COMPARE THE COMMON SUBSTRINGS FROM THE BOTH
def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    sub_a = sub_string(a, n)
    sub_b = sub_string(b, n)
    print(sub_a)
    print(sub_b)
    return common(sub_a, sub_b)