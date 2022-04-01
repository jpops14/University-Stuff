import random

def simplify_sentence(text,word_length,word_count):  
    end_char=text[-1]
    text=text[:-1].split()                  # We save the final char, which is a punctuation mark, to preserve the form of the sentence
    result=[]
    for x in text:                          
        if len(x) <= word_length:
            result.append(x)
    if len(result)<=word_count:             # Picking only words of appropriate length
        return " ".join(result)+end_char
    remove_count=len(result)-word_count     # Number of words left to remove
    for i in range(1,remove_count+1):
        result.pop(random.randint(0,len(result)-1))   # Removing random words
    return " ".join(result)+end_char                  # Restoring the final punctuation mark.
        
            

tekst = "Podział peryklinalny inicjałów wrzecionowatych \
kambium charakteryzuje się ścianą podziałową inicjowaną \
w płaszczyźnie maksymalnej."
print(simplify_sentence(tekst,10,5))
tekst = "Nie było to zaprawdę rzeczą trudną; Utterson bowiem nie miał absolutnie daru strofowania ludzi; przyjaźni jego opierały się właśnie na tej jego bezwzględnej dobroduszności."
print(simplify_sentence(tekst,10,13))
 # tested on fragment of this book: https://wolnelektury.pl/katalog/lektura/stevenson-dr-jekyll-i-mr-hyde.html (legal source)       

short_sentence2 = "Why so many words." # Fails, returns a list? Also punctuation is gone.
print(simplify_sentence(short_sentence2, 10, 5))