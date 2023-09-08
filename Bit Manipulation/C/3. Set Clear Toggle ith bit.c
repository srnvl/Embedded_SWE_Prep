#include <stdio.h>

int set_clear_toggle(int n, int i) {
    int k;
    printf("Enter an operation:\n1. Set\n2. Clear\n3. Toggle\n");
    scanf("%d", &k);

    int result;  // Declare result here to use it outside the switch

    switch (k) {
        case 1:
            {
                int set_mask = 1 << i;
                result = set_mask | n;
                break;
            }
        case 2:
            {
                int clear_mask = ~(1 << i);
                result = clear_mask & n;
                break;
            }
        case 3:
            {
                int toggle_mask = (1 << i);
                result = toggle_mask ^ n;
                break;
            }
        default:
            printf("Error!\n");
            result = n; // Assign n to result in case of an error
            break;
    }
    
    return result;
}

int main() {
    int n = 5;
    int k = 1;
    int result = set_clear_toggle(n, k);
    printf("Result is: %d\n", result);
    return 0;
}
