# ---->>>> Used the built-in method of 'intersection' in Python3
'''

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000
    
'''

def intersection(nums1, nums2):
  nums1 = set(nums1)
  # Set returns the unique values present in a list
  # print(nums1)
  nums2 = set(nums2)
  # print(nums2)
  intersection = nums1.intersection(nums2)
  # print(intersection)
  return intersection

nums1 = [1, 2, 2, 1]
nums2 = [2, 2]
result = intersection(nums1, nums2)
print(result)  # Output: [2]
