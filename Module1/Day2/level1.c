#include <stdio.h>

void printExponent(double x) {
    unsigned long long *ptr = (unsigned long long *)&x;
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52;
    unsigned int hexExponent = (unsigned int)exponent;
    unsigned long long binaryExponent = exponent;

    printf("Hexadecimal: 0x%X\n", hexExponent);
    printf("Binary: 0b");
    
    int i;
    for (i = 11; i >= 0; i--) {
        unsigned int bit = (binaryExponent >> i) & 1;
        printf("%u", bit);
    }
    
    printf("\n");
}

int main() {
    double x = 0.7;
    printExponent(x);

    return 0;
}
