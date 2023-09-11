/*

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 

Constraints:

    1 <= s.length <= 105
    s[i] is a printable ascii character.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};

int main() {
    Solution s;

    // Test case 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original string for test case 1: ";
    for(char c : s1){
        cout << c;
    }
    cout << endl;
    s.reverseString(s1);
    cout << "Reversed string for test case 1: ";
    for(char c : s1){
        cout << c;
    }
    cout << endl;

    // Test case 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "Original string for test case 2: ";
    for(char c : s2){
        cout << c;
    }
    cout << endl;
    s.reverseString(s2);
    cout << "Reversed string for test case 2: ";
    for(char c : s2){
        cout << c;
    }
    cout << endl;

    return 0;
}
