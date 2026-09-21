#include <stdio.h>
#include <string.h>

int main()
{

    char fruits[][10] = {"apple", "banana", "coconut", "pinapple", "lemon"};


    int size = sizeof(fruits) / sizeof(fruits[0]); 

    for (int i = 0; i< size; i++)
    {
        printf("%s\n", fruits[i]);
    }

    fruits[0][1] = 'e';
    fruits[0][4] = 'a';

    for (int i = 0; i< size; i++)
    {
        printf("%s\n", fruits[i]);
    }

    // Exercise

    // 3 Names max 25 chars
    char names[3][25] = {0};

    // printf("Enter a name: ");
    // fgets(names[0], sizeof(names[0]), stdin);
    // names[0][strlen(names[0]) - 1] = '\0';


    // printf("Enter a name: ");
    // fgets(names[1], sizeof(names[1]), stdin);
    // names[1][strlen(names[1]) - 1] = '\0';



    // printf("Enter a name: ");
    // fgets(names[2], sizeof(names[2]), stdin);
    // names[2][strlen(names[2]) - 1] = '\0';



    for (int i = 0; i < 3; i++)
    {
        printf("Enter your name: ");
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strlen(names[i]) - 1] = '\0';
    }

    // printf("%s\n", names[0]);
    // printf("%s\n", names[1]);
    // printf("%s\n", names[2]);

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", names[i]);
    }



    return 0;
}