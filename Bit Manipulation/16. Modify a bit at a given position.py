# 16. Modify a bit at a given position

'''
Given a number n, a position p and a binary value b, we need to change the bit at position p in n to value b.

Examples : 

Input : n = 7, p = 2, b = 0
Output : 3
7 is 00000111 after clearing bit at 
2nd position, it becomes 0000011.

Input : n = 7, p = 3, b = 1
Output : 15
7 is 00000111 after setting bit at 
3rd position it becomes 00001111.

'''

def ModifyBit(n, p, b):
    mask = 1 << p
    return ((n & ~mask) | (b << p))

mod1 = ModifyBit(6, 2, 0)
mod2 = ModifyBit(6, 5, 1)
print(mod1)
print(mod2)
