'''

Given an integer, find the position of leftmost bit set

Example:

n = 9 (1001)
Output: 4

n = 4 (100)
Output: 3

'''

def leftMostSetBit(n):
    pos = 0
    while(n):
        pos += 1
        n = n >> 1
    return pos

# Driver code

a = 9
b = 4
l1 = leftMostSetBit(a)
l2 = leftMostSetBit(b)
print(l1)
print(l2)
