'''

Isolate the right most set bit of a given number

Example- 
Input: 12 (1100)
Output: 4 (0100)

'''

def IsolateRightMostBitSet(n):
    n = n & ~(n-1)
    return n

n = 12
iso = IsolateRightMostBitSet(n)
print(iso)
