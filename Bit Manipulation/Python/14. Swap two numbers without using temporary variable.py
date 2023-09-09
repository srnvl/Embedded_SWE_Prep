# Given two variables, x, and y, swap two variables without using a third variable.

'''
# Using Addition and Subtraction
def swapWOtemp(x, y):
    x = x + y
    y = x - y
    x = x - y
    return x, y

a = 10
b = 5
swap = swapWOtemp(a, b)
print(swap)

'''
def swapWOtemp(x, y):
    x = x ^ y
    y = x ^ y
    x = x ^ y
    return x, y

a = 30
b = 50
swap = swapWOtemp(a, b)
print(swap)
