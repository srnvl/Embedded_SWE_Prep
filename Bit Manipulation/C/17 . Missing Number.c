int missingNumber(int* nums, int numsSize){
    int x1 = 0;
    int x2 = 0;

    // Calculate XOR of each element in nums
    for (int i = 0; i < numsSize; i++)
    {
        x1 = x1 ^ nums[i];
    }

    // Calculate XOR of numbers from 0 to n
    for (int i = 0; i <= numsSize; i++)
    {
        x2 = x2 ^ i;
    }

    return x1 ^ x2;

}
