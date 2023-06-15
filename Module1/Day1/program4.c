#include <stdio.h>

int main() {
    float num1, num2;
    char operator;
    printf("Enter Operand 1: ");
    scanf("%f", &num1);
    printf("Enter Operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter Operand 2: ");
    scanf("%f", &num2);

    float res;
    switch (operator) {
        case '+':
            res=num1+num2;
            break;
        case '-':
            res= num1-num2;
            break;
        case '*':
            res=num1*num2;
            break;
        case '/':
            res=num1/num2;
            break;
        default:
            printf("Invalid operator.\n");
            return 0;
    }

    printf("Result: %f\n", res);

    return 0;
}