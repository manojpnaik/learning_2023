#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseAndInitialize(char *inputString, struct Student *students, int numStudents) {
    char *token = strtok(inputString, " ");  

    int i = 0;
    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token);  
        token = strtok(NULL, " ");  

        if (token != NULL) {
            strncpy(students[i].name, token, sizeof(students[i].name));  
            students[i].name[sizeof(students[i].name) - 1] = '\0';  
            token = strtok(NULL, " ");  

            if (token != NULL) {
                students[i].marks = atof(token);  
                i++;
            }
        }
    }
}

int main() {
    char inputString[] = "1001 Aron 100.00";
    int numStudents = 1;  // Number of students to initialize (can be modified)

    struct Student students[numStudents];
    parseAndInitialize(inputString, students, numStudents);

    // Print the initialized students
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    return 0;
}
