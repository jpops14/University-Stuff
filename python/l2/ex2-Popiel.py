def sqrt(n):           
    ksum=0
    if n==1:
        return 1;
    for i in range(1,n+1):      # adding subsequent elements of sum until it becomes higher than n
        ksum+=2*i-1
        if ksum>n:
            return i-1
            
    return 0;     
        


print (sqrt(0))
print (sqrt(1))
print (sqrt(9))
print (sqrt(11))
print (sqrt(19))
print (sqrt(24))