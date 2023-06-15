#include <stdio.h>

// Function to perform bit operations
int bit_operations(int num, int oper) {
    int res;

    switch (oper) {
        case 1:
            res= num | (1 << 0);
            break;
        case 2:
            res = num & ~(1 << 31);
            break;
        case 3:
            res = num ^ (1 << 15);
            break;
        default:
            printf("Invalid operation type.\n");
            return num;  
    }

    return res;
}

int main() {
    int num, oper;
    printf("Enter an integer (32 bits): ");
    scanf("%d", &num);
    printf("Enter the operation type (1, 2, or 3): ");
    scanf("%d", &oper);
    int res = bit_operations(num, oper);
    printf("Result: %d\n", res);

    return 0;
}
