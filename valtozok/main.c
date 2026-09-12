#include <stdio.h>
#include <string.h>

int main()
{
    int age;
    float gpa;
    char grade;
    char name[30];
    // Making vars unassinged.

    printf("%d\n", age); // 0
    printf("%f\n", gpa); // 0.0000000
    printf("%c\n", grade); // null
    printf("%s\n", name); // null

    // scanf is used for getting user input (type, &variableToStoraAt)
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gpa: ");
    scanf("%f", &gpa);

    getchar(); // Makes the input puffer empty, else it would containt the enter character (\n)
    printf("Enter your grade: ");
    scanf("%c", &grade);


    getchar();
    // filegetstring
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin); // scanf cant read spaces fgets(variableToStore, sizeOfArray, inputFrom)
    name[strlen(name) - 1] = '\0'; // Making the last character a null terminator to stop reading.


    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);
    

    return 0;
}