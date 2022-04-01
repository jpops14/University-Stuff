
def compress(text):
    compressed=[]
    counter=1
    last_char=text[0]                                                 
    for x in text[1:]:
        if x!= last_char:                                  
            compressed.append((counter,last_char))  # when we come to an end of sequence of same characters, we save the character and number of them
            counter = 1
            last_char=x
        else:
            counter=counter+1;                     # otherwise we increment the counter
    compressed.append((counter,last_char))        
    return compressed        

def decompress(compressed):
    text=""                            #restoring the text using simple string/char multiplication
    for count,char in compressed:
        text+=count*char
    return text

test="aaabbc.ccd,ff ff"
compressed=compress(test)
print(compressed)    
print(decompress(compressed))
        
        
 # tested on fragment of this book: https://wolnelektury.pl/katalog/lektura/stevenson-dr-jekyll-i-mr-hyde.html (legal source) 
test="Adwokat Utterson był to człowiek o niezbyt uprzejmej twarzy, której nigdy uśmiech nie opromieniał.  \
 Był to człowiek zimny, małomówny, nieskory do rozmowy; nie zdradzał nigdy skłonności do przejawiania uczuć. \
 Był chudy, wysoki, oschły, mrukliwy — a jednak z jakiegoś powodu lubiano go… W towarzystwie przyjaciół, przy winie, \
  z oczu jego wybłyskiwało umiłowanie ludzkości, coś, czego nigdy odkryć nie można było w jego słowach, a raczej w jego czynach. \
   Był surowy wobec samego siebie; pił gin, gdy był sam, by sobie zepsuć smak wina; chociaż był miłośnikiem teatru, od dwudziestu lat \
    nie był na żadnym przedstawieniu. "
compressed=compress(test)
print(compressed)    
print(decompress(compressed))      