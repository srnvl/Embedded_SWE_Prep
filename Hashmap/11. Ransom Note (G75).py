'''
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters
'''
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if (len(ransomNote) > len(magazine)):
            return False
        count = {}
        for i in magazine:
            if i in count:
                count[i] += 1
            else:
                count[i] = 1
        for i in ransomNote:
            if i not in count:
                return False
            if count[i] == 0:
                return False
            count[i] -= 1
        return True 
