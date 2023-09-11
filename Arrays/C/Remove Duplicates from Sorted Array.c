#include <stdio.h>
#include <stdlib.h>

int* removeDuplicates(int *nums, int numsSize) {
    if (numsSize <= 1) {
        // If there are 0 or 1 elements, there are no duplicates.
        return nums;
    }

    int* temp = (int*)malloc(numsSize * sizeof(int));
    int newSize = 1; // Initialize the size of the new array.

    temp[0] = nums[0]; // The first element is always unique.

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            temp[newSize] = nums[i];
            newSize++;
        }
    }

    return temp;
}

int main() {
    int nums[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int* res = removeDuplicates(nums, numsSize);
    int resSize = numsSize; // The size of the result array is not necessarily the same as the input array.

    for (int i = 0; i < resSize; i++) {
        printf("%d ", res[i]);
    }

    free(res); // Free the dynamically allocated memory.
    return 0;
}
