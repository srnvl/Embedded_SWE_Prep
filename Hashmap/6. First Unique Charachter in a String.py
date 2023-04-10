class Solution:
    def firstUniqChar(self, s: str) -> int:
        di = {}
        for i in s:
            if i not in di:
                di[i] = 1
            else:
                di[i] += 1
        print(di)
        for i in range(len(s)):
            if(di[s[i]] == 1):
                return i
        return -1
  
# create a Solution instance
sol = Solution()

# test case 1
s = "leetcode"
print(sol.firstUniqChar(s)) # Output: 0

# test case 2
s = "loveleetcode"
print(sol.firstUniqChar(s)) # Output: 2

# test case 3
s = "aabb"
print(sol.firstUniqChar(s)) # Output: -1
