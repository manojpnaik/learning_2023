#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Not Valid");
        return 0;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int num;
        printf("Enter integer %d: ", i);
        scanf("%d", &num);
        int temp = num;
        while (temp != 0) {
            int digit = temp % 10;
            if (digit < min) {
                min = digit;
            }
            if (digit > max) {
                max = digit;
            }
            temp /= 10;
        }
    }
    if (min == INT_MAX || max == INT_MIN) {
        printf("Not Valid");
    } else {
        printf("%d and %d", min, max);
    }
}
