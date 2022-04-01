

def sqrt(n):
    """
    sqrt(n) calculates the rounded down value of square root of integer n;
    if type of argument is different to int, a TypeError is raised;
    if argument is a negative integer, a ValueError is raised;
    """
    if not type(n) == int:
        raise TypeError()
    ksum = 0
    if n < 0:
        raise ValueError()
    if n == 1:
        return 1
    for i in range(1, n+1):
        ksum += 2*i-1
        if ksum > n:
            return i-1
    return 0
