'''
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2

Example 2:

Input: nums = [3,1,3,4,2]
Output: 3

 

Constraints:

    1 <= n <= 105
    nums.length == n + 1
    1 <= nums[i] <= n
    All the integers in nums appear only once except for precisely one integer which appears two or more times.
'''

    def findDuplicate(nums):
        '''
        Create a dictionary to solve:
        Easiest method for a medium level problem :p

        di = {}
        for i in nums:
            if i in di.keys():
                di[i] += 1
                return i
            else:
                di[i] = 1
        '''

        # Using XOR Approach:

        maxVal = max(nums)
        minVal = min(nums)
        # print(minVal)
        # print(maxVal)
        temp = []

        if(minVal == maxVal):
            return minVal
        else:
            for i in range(minVal, maxVal+1):
                temp.append(i)
            print(temp)

            res1 = 0
            res2 = 0
            for i in nums:
                res1 = res1 ^ i
            print(res1)

            for i in temp:
                res2 = res2 ^ i
            print(res2)

            return res1 ^ res2
