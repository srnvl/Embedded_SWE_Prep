/*
/// Implement strStr()
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 

Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.




*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // size_t found = haystack.find(needle);     //// We use find() function which is of type size_t to return the index. size_t means that the number is very big, around upto 32 bit and is unsigned.
        // if(found != string::npos) 
        //   // If the substring is not found, the find() function returns string::npos, which is a special value indicating that the substring was not found.
        // {
        //     return found;
        // }
        // return -1;
     // Alternate solution:
        int n = needle.size();
        for(int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0] && haystack.substr(i, n) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution s;
    
    int i = s.strStr(haystack, needle);   
    if(i != 1)
    {
        cout << i << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    
    return 0;
}
