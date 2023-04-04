# The bit manipulation method works for both only set bit and as well as for a number occuring odd number of times

'''
Given an array of positive integers. All numbers occur an even number of times except one number which occurs an odd number of times.
Find the number in O(n) time & constant space.

Examples : 

    Input : arr = {1, 2, 3, 2, 3, 1, 3}
    Output : 3

    Input : arr = {5, 7, 2, 7, 5, 2, 5}
    Output : 5



def getOddNumberOfInteger(arr):
    di = {}
    for i in arr:
        if i in di:
            di[i] += 1
        else:
            di[i]  = 1
    for i in di.keys():
        if (di[i] % 2 != 0):
            return i
    return -1

'''


def getOddNumberOfInteger(arr):
    res = 0
    for i in arr:
        res = res ^ i
    return res


arr = [1,2,3,2,3,1,3]
OddNumber = getOddNumberOfInteger(arr)
print(OddNumber)
