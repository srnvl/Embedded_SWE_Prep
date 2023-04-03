# Add two numbers without arithmetic oprators

def addTwoNums(a, b):
    while(b):
        carry = a & b   # To calculate carry, we use AND operation
        a = a ^ b       # To add, we use XOR operation
        b = carry << 1  # Shift the carry by one to propogate it to the further bit
    return a
  
res = addTwoNums(3, 1)
print(res)
