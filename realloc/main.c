#include <stdio.h>
#include <stdlib.h>


int main()
{
    // realloc() = Reallocation.
    // Resize prev allocated memory.

    int number = 0;

    printf("Enter the number of prices: ");
    scanf("%d", &number);

    float* prices = malloc(number * sizeof(float));

    if (prices == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    for (int i = 0; i < number; i++)
    {
        printf("Enter the price #%d: ", i+1);
        scanf("%f", &prices[i]);
    }

    int newNumber = 0;
    printf("Enter a new number of prices: ");
    scanf("%d", &newNumber);

    float* temp = realloc(prices, newNumber * sizeof(float));

    if (temp == NULL)
    {
        printf("Error reallocating!\n");
        return 1;
    }
    else
    {
        prices = temp;
        temp = NULL;

        for (int i = number; i < newNumber; i++)
        {
            printf("Enter the price #%d: ", i+1);
            scanf("%f", &prices[i]);
        }

    }

    

    for (int i = 0; i < newNumber; i++) printf("Price #%d: %.2f\n", i+1, prices[i]);


    free(prices);
    prices = NULL;

    return 0;
}