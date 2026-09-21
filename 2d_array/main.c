#include <stdio.h>


int main()
{
    // 2D array is an array where the element itself is an array inside the array
    // You must declare the column.
    int numbers[][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9},
                        {10, 11, 12}};

    
    printf("%d\n", numbers[0][0]); // 0th row and 0th column
    printf("%d\n", numbers[2][3]); // 2nd row and 3rd column

    for (int i = 0; i < 4; i++) //row
    {
        for (int j = 0; j < 3; j++) // column
        {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }


    char numpad[][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'*', '0', '#'}};

    printf("\n");
    for (int i = 0; i < 4; i++) //row
    {
        for (int j = 0; j < 3; j++) // column
        {
            printf("%c ", numpad[i][j]);
        }
        printf("\n");
    }


    printf("%d\n", sizeof(numbers)); // All
    printf("%d\n", sizeof(numbers[0])); // The first array
    printf("%d\n", sizeof(numbers[0][0])); // The value inside the array

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        for (int j = 0; j < sizeof(numbers[0]) / sizeof(numbers[0][0]); j++)
        {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }


    return 0;
}