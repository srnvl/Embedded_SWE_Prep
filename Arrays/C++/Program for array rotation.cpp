#include <iostream>
#include <vector>

using namespace std;

void rotateArrayLeft(vector<int>&nums, int d)
{
    int temp[nums.size()];
    
    int k = 0;
    
    for(int i = d; i < nums.size(); i++)
    {
        temp[k] = nums[i];
        k++;
    }
    
    for(int i = 0; i < d; i++)
    {
        temp[k] = nums[i];
        k++;
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }
}

void rotateArrayRight(vector<int> &nums, int d)
{
    int temp[nums.size()];
    
    int k = 0;
    
    for(int i = d + 1; i < nums.size(); i++)
    {
        temp[k] = nums[i];
        k++;
    }
    
    for(int i = 0; i <= d; i++)
    {
        temp[k] = nums[i];
        k++;
    }
    
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }    
    
}

void printArray(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int d = 2;
    // rotateArrayLeft(nums, d);
    // printArray(nums);
    // cout <<"\n";
    rotateArrayRight(nums, d);
    printArray(nums);
    return 0;
}
