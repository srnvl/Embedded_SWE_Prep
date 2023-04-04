# Toggling the rightmost set bit

'''
Write a program that unsets the rightmost set bit of an integer. 
Examples : 
 

Input:  12 (00...01100)
Output: 8 (00...01000)

Input:  7 (00...00111)
Output: 6 (00...00110)

'''

def TogglingRightmostBitSet(n):
    n = n & (n - 1)
    n = bin(n)
    return n

n = 7
toggle = TogglingRightmostBitSet(n)
print(toggle)
