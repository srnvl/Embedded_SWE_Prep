# Swap all odd and even bits

'''
Given an unsigned integer N.
The task is to swap all odd bits with adjacent even bits.

Input: 23
Output: 43
Explanation: 23 (00010111) should be converted to 43 (00101011).

Input: 2
Output: 1
'''

def swap_bits(num):

    even_mask = 0xAAAAAAAA  # 1010101010101010 in binary

    odd_mask = 0x55555555  # 0101010101010101 in binary

    even_bits = num & even_mask
    odd_bits = num & odd_mask
    
    # Shift to swap the positions of even bits and odd bits
    
    even_bits >>= 1
    odd_bits <<= 1

    swapped_num = even_bits | odd_bits

    return swapped_num


num = 0b00010111  # 23 in decimal
swapped_num = swap_bits(num)
print(bin(swapped_num).replace("0b", ""))  # 00101011 -> 43 in decimal
