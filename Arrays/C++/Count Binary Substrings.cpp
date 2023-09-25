#include <iostream>
#include <string>

int countBinarySubstrings(const std::string& s) {
    int count = 0;
    int prevCount = 0;
    int currentCount = 1;
    
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            currentCount += 1;
        } else {
            prevCount = currentCount;
            currentCount = 1;
        }
        
        if (prevCount >= currentCount) {
            count += 1;
        }
    }
    
    return count;
}

int main() {
    std::string input = "0011";
    int result = countBinarySubstrings(input);
    std::cout << "Count of valid binary substrings: " << result << std::endl;
    return 0;
}
