import math


def prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)), 2):
        if n % i == 0:
            return False
    return True

def add(n):
    ans = n
    n //= 10
    while n > 0:
        ans = ans * 10 + (n % 10)
        n //= 10
    return ans


n = int(input())
n = add(n)
if prime(n) == True:
    print("prime")
else:
    print("noprime")