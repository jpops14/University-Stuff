import timeit


def perfect_imperative(n):
    result=[]
    for i in range (2,n+1):
        divisor_sum=0
        for j in range(1,i):                 #simple algorithm for calculating sum of divisors, similar complexity to Comprehension and Functional verison
            if i%j==0:                       #allows for better comparison
                divisor_sum+=j
        if divisor_sum==i:
            result.append(i);
    return result
    
def perfect_comprehension(n):              
    return [i for i in range(2,n+1) if i==sum([j for j in range(1,i) if i%j==0])]

def perfect_functional(n):
    return list(filter(lambda x: x==sum([j for j in range(1,x) if x%j==0]),range(2,n+1)))


print(perfect_imperative(1000))
print(perfect_comprehension(1000))
print(perfect_functional(1000))

# execution time tests
setu = '''from __main__ import perfect_imperative
from __main__ import perfect_comprehension
from __main__ import perfect_functional'''

print("n= 2^10")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='perfect_imperative(2**10)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='perfect_comprehension(2**10)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='perfect_functional(2**10)', number=1)}")

print("n= 2^12")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='perfect_imperative(2**12)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='perfect_comprehension(2**12)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='perfect_functional(2**12)', number=1)}")

print("n= 2^14")
print(f"Imperative: {timeit.timeit(setup=setu, stmt='perfect_imperative(2**14)',number=1)}")
print(f"Comprehension: {timeit.timeit(setup=setu, stmt='perfect_comprehension(2**14)', number=1)}")
print(f"Functional: {timeit.timeit(setup=setu, stmt='perfect_functional(2**14)', number=1)}")

#print("n= 2^16")
#print(f"Imperative: {timeit.timeit(setup=setu, stmt='perfect_imperative(2**16)',number=1)}")
#print(f"Comprehension: {timeit.timeit(setup=setu, stmt='perfect_comprehension(2**16)', number=1)}")
#print(f"Functional: {timeit.timeit(setup=setu, stmt='perfect_functional(2**16)', number=1)}")


# regardless of given n, all three implementions take around the same amount of time to complete calculations
# for n= 2^16 all functions take about 80 seconds to finish, no point in further testing