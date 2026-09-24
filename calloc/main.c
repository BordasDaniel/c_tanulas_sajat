#include <stdio.h>
#include <stdlib.h>


int main()
{   
    // calloc() = Contigoues allocation
    // Allocates memory dynamically and sets all allocated bytes to 0.
    
    int number = 0;
    printf("Enter the number of players: ");
    scanf("%d", &number);

    int* scores = calloc(number, sizeof(int)); // calloc(elementNumbers, size);
    // WIth malloc it could lead to undefined behavior.

    if (scores == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < number; i++)
    {
        printf("%d ", scores[i]);
    }

    free(scores);
    scores = NULL;


    return 0;
}