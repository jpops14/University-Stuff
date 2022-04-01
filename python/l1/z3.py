import math


def digits(n):
    return (int(math.log10(n))+1)
def adjust(n,width):
    return ((width-digits(n))*" "+str(n))

def mult_table(x1,x2,y1,y2):
    width=digits(x2*y2)
    line=width*" "
    for i in range(x1,x2+1):
        line+=" "+adjust(i,width)
    print(line)
    
    for y in range (y1,y2+1):
        line=adjust(y,width)
        for x in range (x1,x2+1):
            number=y*x
            prefix=(width-digits(i)+1)*" "
            line+=" "+adjust(number,width)
        print(line)    
            


mult_table(3,5,2,4)
