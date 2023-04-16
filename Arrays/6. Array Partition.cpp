/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.

Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.

 

Constraints:

    1 <= n <= 10^4
    nums.length == 2 * n
    -10^4 <= nums[i] <= 10^4

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int sum = 0;

        for(int i = 0; i < nums.size(); i = i + 2){
            res.push_back(nums[i]);
        }

        for(int i = 0; i < res.size(); i++)
        {
            sum = sum + res[i];
        }

        return sum;
    }
};

int main() {
    Solution s;

    // Test case 1
    vector<int> nums1 = {1, 4, 3, 2};
    cout << "Array pair sum for test case 1: " << s.arrayPairSum(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {5, 7, 1, 4, 6, 2};
    cout << "Array pair sum for test case 2: " << s.arrayPairSum(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {3, 1, 2, 5, 6, 4};
    cout << "Array pair sum for test case 3: " << s.arrayPairSum(nums3) << endl;

    return 0;
}
