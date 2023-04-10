'''
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

 

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.

'''

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        di_s = []   # Stores the index of the charachters of the string s
        di_t = []   # Stores the index of the charachters of the string t
        for i in s:
            di_s.append(s.index(i))
            # Note: Index always returns the index of first occurence of a charachter
            # print(di_s)
        for i in t:
            di_t.append(t.index(i))
            # print(di_t)
        if di_s == di_t:
            return True
        return False

solution = Solution()

# Test case 1: s and t are isomorphic
s1 = "paper"
t1 = "title"
print(solution.isIsomorphic(s1, t1))   # Output: True

# Test case 2: s and t are not isomorphic
s2 = "foo"
t2 = "bar"
print(solution.isIsomorphic(s2, t2))   # Output: False
