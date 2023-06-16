#include <stdio.h>

int findLargNum(int num) {
    int largest = 0;

    for (int i = 0; i < 4; i++) {
        int divisor = 1;
        int temp = num;

        for (int j = 0; j < i; j++) {
            divisor *= 10;
        }
        temp = (temp / (divisor * 10)) * divisor + (temp % divisor);

       
        if (temp > largest) {
            largest = temp;
        }
    }

    return largest;
}

int main() {
    int num;

    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largest = findLargNum(num);
    printf("The largest number after deleting a single digit: %d\n", largest);

    return 0;
}
