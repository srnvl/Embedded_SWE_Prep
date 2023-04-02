# Power of 2

'''
Given a positive integer n, write a function to find if it is a power of 2 or not

Examples: 

    Input : n = 4
    Output : Yes
    Explanation: 22 = 4

    Input : n = 32
    Output : Yes
    Explanation: 25 = 32

'''

# Before the implementation of the main program, here's the implementation of Brian Kernighan's Algorithm to count set bits of a number:
# Write an efficient program to count the number of 1s in the binary representation of an integer.
# Examples : 

#     Input : n = 6
#    Output : 2
#    Binary representation of 6 is 110 and has 2 set bits

#    Input : n = 13
#    Output : 3
#    Binary representation of 13 is 1101 and has 3 set bits

# This is Brian Kernighan's Algorithm to count set bits in a given number
'''
def countSetBits(n):
 
    count = 0
    while (n != 0):
        n = n & (n-1)
        count+= 1
    return count
 
# Program to test function countSetBits
i = 9
print(countSetBits(i))
'''

# This is a modification of Brian Kernighan's Algorithm where we find the count to be exactly to be one. If it is one, then the number is a power of 2.
# Consider the examples:
# 4 --> 100, 8 --> 1000, 2 --> 10. Here, each of power of 2 has exactly only one in their binary representation.

def powerOfTwo(x):
    temp = 0
    def countSet(c):
        nonlocal temp
        # nonlocal is a keyword in Python that is used inside a nested function to indicate that a variable is not local to the function. 
        # In other words, it tells Python that the variable is defined in an outer function or global scope, 
        # and should be accessed and modified by the nested function.
        count = 0
        while(c != 0):
            c = c & (c - 1)
            count += 1
        temp = count
    countSet(x)
    if(temp == 1):
        return True
    return False
    
n = 4
print(powerOfTwo(n))
