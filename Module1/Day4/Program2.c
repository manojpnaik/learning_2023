#include <stdio.h>

int main() {
    int array[] = {5, 2, 9, 1, 7, 3, 6};
    int size = sizeof(array) / sizeof(array[0]);

    int min = array[0];  // Initialize min with the first element
    int max = array[0];  // Initialize max with the first element

    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];  // Update min if a smaller element is found
        }

        if (array[i] > max) {
            max = array[i];  // Update max if a larger element is found
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
