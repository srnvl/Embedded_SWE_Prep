# include <stdio.h>
# include <stdbool.h>

int singleNumber(int* nums /* or int nums[] */, int numsSize)
{
    int result = 0;
    for(int i = 0; i < numsSize; i++)
    {
        result = result ^ nums[i];
    }
    return result;
}

int main()
{
    int nums1[] = {2, 2, 1};
    int res = singleNumber(nums1, (sizeof(nums1)/sizeof(nums1[0])));
    printf("Res: %d", res);
    return 0;
}
