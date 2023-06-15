#include <stdio.h>

// Function to calculate the total marks
int calculateTotal(int physics, int math, int chemistry) {
    return physics + math + chemistry;
}

// Function to calculate the percentage
float calculatePercentage(int total) {
    return (float)total / 3;
}

int main() {
    int rollNo, physics, math, chemistry;
    char name[50];

    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %s", name);

    printf("Enter Marks in Physics: ");
    scanf("%d", &physics);

    printf("Enter Marks in Maths: ");
    scanf("%d", &math);

    printf("Enter Marks in Chemistry: ");
    scanf("%d", &chemistry);

    int total = calculateTotal(physics, math, chemistry);
    float percentage = calculatePercentage(total);

    printf("\nSummary\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %d\n", physics);
    printf("Maths Marks: %d\n", math);
    printf("Chemistry Marks: %d\n", chemistry);
    printf("Total Marks: %d\n", total);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}