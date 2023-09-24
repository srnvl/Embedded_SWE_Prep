class Solution 
{
public:
    int countBinarySubstrings(string s) 
    {
        int res = 0;
        
        int prevCount = 0;
        int currCount = 1; //s[0]
        
        for(int i=1; i<s.size(); i++)
        {
            if (s[i] == s[i-1])
                currCount++;
            else
            {
                res = res + min({prevCount, currCount});
                prevCount = currCount;
                currCount = 1;
            }
        }
        
        res = res + min({prevCount, currCount}); // for the last group
        return res;
    }
};
