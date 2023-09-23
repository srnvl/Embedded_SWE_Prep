#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int pos = 1;
  for(int i = 1; i < nums.size(); i++)
  {
    if(nums[i] > nums[i - 1]){
      nums[pos] = nums[i];
      pos++;
    }
  }
  return pos;
}

int main()
{
  vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5};

  int newSize = removeDuplicates(nums);

  cout << "Original vector: ";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  cout << "After removing duplicates: ";
  for (int i = 0; i < newSize; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}
