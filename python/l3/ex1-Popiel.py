import timeit


def prime_imperative(n):
    result=[]
    for i in range (2,n+1):
        isPrime=True;
        for j in range(2,i):     # naive algorithm for calculating prime numbers, not effective but similiar to Comprehension and functional
            if i%j==0:           # implementations, which gives us a more precise comparison
                isPrime=False;
                break;
        if isPrime:
            result.append(i);
    return result
    
def prime_comprehension(n):            #using all operator to make sure n is not divisible by anything greater than 1 
    return [i for i in range (2,n+1) if all([i%j != 0 for j in range (2,i)])]
    
def prime_functional(n):         #using all operator to make sure n is not divisible by anything greater than 1
    return list(filter(lambda x: all(x%i != 0 for i in range(2,x)),range(2,n+1)))
    
  

print(prime_imperative(100))
print(prime_comprehension(100));
print(prime_functional(100));


# execution time tests
setu = '''from __main__ import prime_imperative
from __main__ import prime_comprehension
from __main__ import prime_functional'''

print("n= 2^10")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='prime_imperative(2**10)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='prime_comprehension(2**10)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='prime_functional(2**10)', number=1)}")

print("n= 2^12")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='prime_imperative(2**12)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='prime_comprehension(2**12)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='prime_functional(2**12)', number=1)}")

print("n= 2^14")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='prime_imperative(2**14)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='prime_comprehension(2**14)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='prime_functional(2**14)', number=1)}")

#print("n= 2^16")
#print(f"Imperative: {timeit.timeit(setup=setu, stmt='prime_imperative(2**16)',number=1)}")
#print(f"Comprehension: {timeit.timeit(setup=setu, stmt='prime_comprehension(2**16)', number=1)}")
#print(f"Functional: {timeit.timeit(setup=setu, stmt='prime_functional(2**16)', number=1)}")

# for n = 2^16 comprehension takes around 100 seconds, so there is no point in further testing
# for small n (ex. <=2^10) comprehension is the fastest, but for bigger data it is the least effective out of the 3 versions
# for big n (ex. >=2^16) imperative version is the fastest, noticeably faster than functional, massively faster than comprehension
# for medium n (between 2^10 and 2^16) functional version is the fastest
