#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[50];
    int age;
    float gpa;
    bool isFullTime;
}Student;

void printStudent(Student student)
{
    printf("%s\n", student.name);
    printf("%d\n", student.age);
    printf("%.2f\n", student.gpa);
    printf("%s\n", (student.isFullTime ? "Full time student" : "Not a full time student"));

}


int main()
{
    // struct = A custom container that holds multiple pieces of related information. Similar to Objects

    Student student1 = {"Spongebob", 30, 2.5, true};
    Student student2 = {"Patrick", 36, 1.0, false};


    printf("%s\n", student1.name);
    printf("%d\n", student1.age);
    printf("%.2f\n", student1.gpa);
    printf("%s\n", (student1.isFullTime ? "Full time student" : "Not a full time student"));

    printf("%s\n", student2.name);
    printf("%d\n", student2.age);
    printf("%.2f\n", student2.gpa);
    printf("%s\n", (student2.isFullTime ? "Full time student" : "Not a full time student"));
    

    Student student3 = {0}; // Empty

    strcpy(student3.name, "Sandy"); // Copying data after creation.
    student3.age = 27;
    student3.gpa = 4.0;
    student3.isFullTime = true;

    printStudent(student3);
    
    return 0;
}