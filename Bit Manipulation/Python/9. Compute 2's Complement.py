# Compute 2's Complement

def twos_complement(num, num_size):

    ones_complement = num ^ ((1 << num_size) - 1)
    twos_comp = ones_complement + 1

    return twos_comp

num = 0b1101
num_size = 4
two_c = twos_complement(num, num_size)
print(bin(two_c).replace("0b", ""))
