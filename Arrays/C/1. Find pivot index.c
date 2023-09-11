#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int *nums, int numsSize)
{
    int rightSum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        rightSum += nums[i]; 
    }
    int leftSum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        rightSum -= nums[i];
        if(leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
}

int main()
{
    int nums[] = {1,7,3,6,5,6};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = pivotIndex(nums, numsSize);
    printf("Pivot index for this array is: %d\n", result);
    return 0;
}
