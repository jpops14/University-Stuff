import string

def is_palindrome(text):
    normalized=(text.translate(str.maketrans('', '', string.punctuation))).replace(" ","").lower()
    reversed=normalized[::-1]
    return (reversed==normalized)
    
print (is_palindrome("Kobyła ma mały bok."))
print (is_palindrome("Eine güldne, gute Tugend: Lüge nie!"))
print (is_palindrome("not a palindrome"))