# Position of the rightmost set bit

'''
Write a one-line function to return the position of the first 1 from right to left, in the binary representation of an Integer. 

Examples:

    Input: n = 18
    Output: 2
    Explanation: Binary Representation of 18 is 010010, hence position of first set bit from right is 2.

    Input:  n = 19
    Output: 1
    Explanation: Binary Representation of 19 is 010011, hence position of first set bit from right is 1.

'''

def positionOfRightMostSetBit(n):
    n = n & ~(n - 1)
    n = bin(n)
    return n


n = 18
pos = positionOfRightMostSetBit(n)
print(pos)
    
