'''
Write an efficient program to count the number of 1s in the binary representation of an integer.
Examples : 

    Input : n = 6
    Output : 2
    Binary representation of 6 is 110 and has 2 set bits

    Input : n = 13
    Output : 3
    Binary representation of 13 is 1101 and has 3 set bits

'''
# This is Brian Kernighan's Algorithm to count set bits in a given number
def countSetBits(n):
 
    count = 0
    while (n != 0):
        n = n & (n-1)
        count+= 1
    return count
 
# Program to test function countSetBits
i = 9
print(countSetBits(i))
