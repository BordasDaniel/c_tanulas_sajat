#include <stdio.h>

typedef char* string;

int main()
{

    FILE *pFile =  fopen("something.txt", "w");
    string text = "Hello\nWorld!";

    if (pFile == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(pFile, "%s", text);

    printf("File was written succesfully!\n");


    return 0;
}