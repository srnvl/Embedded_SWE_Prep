# Reverse the order of bits in a number:

'''
Given a non-negative integer n. The problem is to reverse the bits of n and print the number obtained after reversing the bits. Note that the actual binary representation of the number is being considered for reversing the bits, no leadings 0’s are being considered.
Examples : 
 

    Input : 11
    Output : 13
    Explanation: (11)10 = (1011)2.
    After reversing the bits we get:
    (1101)2 = (13)10.

    Input : 10
    Output : 5
    Explanation : (10)10 = (1010)2.
    After reversing the bits we get:
    (0101)2 = (101)2
            = (5)10
'''


def reverseBits(n):
    rev = 0
    for in in range(32):
        rev = rev << 1 # Reversal logic to XOR with 1 in later stage
        if(n & 1 == 1):
            rev = rev ^ 1
        n = n >> 1
    return rev

n = 4
reverse = reverseBits(n)
print(reverse)
     
