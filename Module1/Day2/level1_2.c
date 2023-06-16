#include <stdio.h>

void swap(void *a, void *b, size_t size) {
    unsigned char *ptrA = (unsigned char *)a;
    unsigned char *ptrB = (unsigned char *)b;

    while (size--) {
        unsigned char temp = *ptrA;
        *ptrA++ = *ptrB;
        *ptrB++ = temp;
    }
}

int main() {
    int x = 5;
    int y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y, sizeof(int));

    printf("After swap: x = %d, y = %d\n", x, y);

    float a = 2.5;
    float b = 7.8;
    printf("Before swap: a = %f, b = %f\n", a, b);

    swap(&a, &b, sizeof(float));

    printf("After swap: a = %f, b = %f\n", a, b);

    return 0;
}
