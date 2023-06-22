#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    int n; 
    struct Student* students; 

    printf("Enter the number of students: ");
    scanf("%d", &n);

    students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter the name: ");
        scanf("%s", students[i].name);

        printf("Enter the age: ");
        scanf("%d", &students[i].age);

        printf("Enter the marks: ");
        scanf("%f", &students[i].marks);
    }

    printf("\nStudent Data:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
