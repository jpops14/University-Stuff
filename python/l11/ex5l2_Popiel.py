def compress(text):
    """
    This function compressess strings to lists in a following manner:
    every continous sequence of same characters is replaced with a
    pair (n,x), where x is the repeated character, and n is the
    length of the sequence. The result returned by this
    function is a list of such pairs.
    """
    compressed = []
    counter = 1
    last_char = text[0]
    for x in text[1:]:
        if x != last_char:
            # when we come to an end of sequence of same characters,
            # we save the character and number of them
            compressed.append((counter, last_char))
            counter = 1
            last_char = x
        else:
            counter = counter + 1  # otherwise we increment the counter
    compressed.append((counter, last_char))
    return compressed


# this function
def decompress(compressed):
    """
    This function turns compressed strings (lists of pairs (n,x)
    where x is a character, and n is the length of the sequence
    of that repeated character) int a string representing the
    original text.
    """
    text = ""  # restoring the text using simple string/char multiplication
    for count, char in compressed:
        text += count * char
    return text
