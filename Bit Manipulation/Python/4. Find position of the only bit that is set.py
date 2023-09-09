# Find position of the only bit that is set

'''
Given a number N having only one "1"s and all other "0"s in its binary representation, find position of the only set bit. 
If there are 0 or more than 1 set bit the answer should be -1.
Position of set bit "1" should be counted starting with 1 from the LSB side in the binary representation of the number.

Examples:-

Input:
N = 2
Output:
2
Explanation:
2 is represented as "10" in Binary.
As we see there's only one set bit
and it's in Position 2 and thus the
Output 2.

here is another example

Input:
N = 5
Output:
-1
Explanation:
5 is represented as "101" in Binary.
As we see there's two set bits
and thus the Output -1.

'''

def isPowerOfTwo(n):
    if(n > 0 and (n & (n-1)) > 0):
        return False
    return True

def findPos(n):
    if(isPowerOfTwo(n) == False):
        return -1
    
    i = 1
    pos = 1

    while((n & i) == 0):
        i = i << 1
        pos += 1
    return pos

n = input("Enter a number: ")
n = int(n)
pos = findPos(n)
if(pos == -1):
    print("Invalid number")
else:
    print(f'The bit is present at {pos}th position')
