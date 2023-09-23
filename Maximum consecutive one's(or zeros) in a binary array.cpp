#include <iostream>
#include <vector>

using namespace std;

int maxConsOne(vector<int> &nums)
{
    //..keep a track of max_count and curr_count of 1s (or 0s as per qsn)
    //..update max count by making max(max_count, curr_count)
    //..if you encounter a 0(or a 1, then make curr count = 0)
    int max_cnt = 0;
    int curr_cnt = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            curr_cnt += 1;
            max_cnt = max(max_cnt, curr_cnt);
        }
        else
        {
            curr_cnt = 0;
        }
    }
    return max_cnt;
}

int main()
{
    vector<int> nums = {1,1,0,0,1,0,1,0,1,1,1,1};
    int current_count = maxConsOne(nums);
    cout << "Number of consecutive 1's is: " << current_count << endl;
    return 0;
}
