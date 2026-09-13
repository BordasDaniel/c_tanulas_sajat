#include <stdio.h>
#include <math.h>


int KgToPounds(float converterValue)
{
    float weight;

    printf("Enter the weight in kilograms: ");
    scanf("%f", &weight);

    printf("%.2f kilograms is equal to %.2f pounds\n", weight, weight * converterValue);

    return 0;
}

int PoundsToKg(float converterValue)
{
    float weight;

    printf("Enter the weight in pounds: ");
    scanf("%f", &weight);

    printf("%.2f pounds is equal to %.2f kilograms\n", weight, weight / converterValue);


    return 0;
}

int main()
{
    const float converterValue = 2.20462f;
    int choice;

    printf("Weight conversion program.\n");
    printf("1. Kilograms to Pounds\n2.Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        KgToPounds(converterValue);
    } else
    {
        PoundsToKg(converterValue);
    }

    return 0;
}