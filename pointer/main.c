#include <stdio.h>


// Pass by value
/*
void birthday(int age)
{
    age++;
}
*/


// Pass by reference
void birthday(int* age)
{
    (*age)++;
}

int main()
{
    // pointer = a variable that stores the memory address of another pointer.
    // Instead of copying it allows direct pass onto another function.


    int age = 25;

    printf("%p\n", &age); // Printing the address.

    int* pAge = &age; // Pointer

    printf("%p\n", pAge); // Printing the address.

    birthday(pAge);
    birthday(&age);

    printf("You are %d years old!\n", age);



    return 0;
}