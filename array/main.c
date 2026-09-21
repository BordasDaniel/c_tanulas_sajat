#include <stdio.h>

int main()
{
    int numbers[] = {10, 20, 30, 40, 50}; // fixed size collection

    printf("%d\n", numbers[1]);
    printf("%d\n", numbers[646]); // random number (out of bounds)

    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    printf("%c\n", grades[3]);

    char name[] = "Random Name";

    printf("%c\n", name[1]); // WIll give an 'a' as a result.


    numbers[0] = 100; // override the value

    printf("%d\n", numbers[0]);

    numbers[67] = 100; 
    printf("%d\n", numbers[66]); // random
    printf("%d\n", numbers[67]); // 100
    printf("%d\n", numbers[68]); // 0 (end of array)

    for (int i = 0; i < 5; i++)
    {
        printf("%c ", grades[i]);
    }

    printf("\n%d\n", sizeof(grades));
    printf("%d\n", sizeof(grades[0]));

    printf("%d\n", sizeof(numbers));
    printf("%d\n", sizeof(numbers[0]));

    int size = sizeof(grades) / sizeof(grades[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%c ", grades[i]);
    }




    return 0;
}