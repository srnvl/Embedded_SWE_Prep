# Set Clear and Toggle ith bit
'''
Given a number N, the task is to set, clear and toggle the i-th bit of this number N.

Setting a bit means that if i-th bit is 0, then set it to 1 and if it is 1 then leave it unchanged.
Clearing a bit means that if i-th bit is 1, then clear it to 0 and if it is 0 then leave it unchanged.
Toggling a bit means that if i-th bit is 1, then change it to 0 and if it is 0 then change it to 1.

Examples:

Input: N = 5, i = 1
Output: 
Setting ith bit: 5
Clearing ith bit: 4
Toggling ith bit: 4
Explanation: 
5 is represented as 101 in binary
and has its first bit 1, so 
setting it will result in 101 i.e. 5.
clearing it will result in 100 i.e. 4.
toggling it will result in 100 i.e. 4.

Input: N = 7, i = 2
Output: 
Setting ith bit: 7
Clearing ith bit: 5
Toggling ith bit: 5
Explanation: 
7 is represented as 111 in binary
and has its second bit 1, so 
setting it will result in 111 i.e. 7.
clearing it will result in 101 i.e. 5.
toggling it will result in 101 i.e. 5.

'''

def set_ith_bit(num, i):
    mask = 1 << i
    set_num =  num | mask
    return set_num

def clear_ith_bit(num, i):
    mask = ~(1 << i)
    clear = num & mask
    return clear

def toggle_ith_bit(num, i):
    mask = 1 << i
    toggle = num ^ mask
    return toggle

num = 23
i = 2

# set the ith bit
S = set_ith_bit(num, i)
print(f"Setting the {i}th bit of {num} to 1 gives: {S}")  # output: Setting the 2th bit of 23 to 1 gives: 27

# toggle the ith bit
T = toggle_ith_bit(num, i)
print(f"Toggling the {i}th bit of {num} gives: {T}")  # output: Toggling the 2th bit of 23 gives: 19

# clear the ith bit
C = clear_ith_bit(num, i)
print(f"Clearing the {i}th bit of {num} gives: {C}") # output : Clearing the 2th bit of 23 gives: 19
