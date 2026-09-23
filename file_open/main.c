#include <stdio.h>

int main()
{
    FILE* pFile = fopen("input.txt", "r");
    char buffer[1024] = {0}; // temp store data. 1024 is a general size

    if (pFile == NULL)
    {
        printf("Could not open the file!\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), pFile) != NULL) printf("%s", buffer);


    fclose(pFile);

    return 0;
}