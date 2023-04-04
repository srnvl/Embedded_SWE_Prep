# Set all bits in a given range

'''

Given a non-negative number n and two values l and r. The problem is to set the bits in the range l to r in the binary representation of n, i.e, to unset bits from the rightmost lth bit to the rightmost r-th bit. 
Constraint: 1 <= l <= r <= number of bits in the binary representation of n.
Examples : 
 
    Input : n = 17, l = 2, r = 3
    Output : 23
    (17)10 = (10001)2
    (23)10 = (10111)2
    The bits in the range 2 to 3 in the binary
    representation of 17 are set.

    Input : n = 50, l = 2, r = 5
    Output : 62

'''

def setAllBits(n, l, r):

    defineRange = ((1 << (l-1))-1) ^ ((1 << r)-1)
    n = n | defineRange
    n = int(n)
    return n

n = 17
l = 2
r = 3
setBit = setAllBits(n, l, r)
print(setBit)
