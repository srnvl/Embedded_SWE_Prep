#include <stdio.h>
#include <stdlib.h>

int main() {
    int* arr_malloc;
    int* arr_calloc;

    arr_malloc = (int*)malloc(100 * sizeof(int)); // *** will allocate a memory block of 1 block whose total size is 400 bytes

    arr_calloc = (int*)calloc(100, sizeof(int)); // *** will allocate a memory block of 100 blocks whose total size is 400 bytes

    // Assigning a value to the allocated integers
    *arr_malloc = 42;
    *arr_calloc = 10;

    // Printing the values
    printf("Value stored in the malloc-allocated integer: %d\n", *arr_malloc);
    printf("Value stored in the calloc-allocated integer: %d\n", *arr_calloc);

    // Deallocating memory
    free(arr_malloc);
    free(arr_calloc);

    return 0;
}
