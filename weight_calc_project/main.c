#include <stdio.h>

void ScreenCleaner(void)
{
    printf("\033[H\033[J");
}

void KgToPounds(float converterValue)
{
    ScreenCleaner();
    float weight;

    printf("Enter the weight in kilograms: ");
    if ((scanf("%f", &weight)) != 1 || weight < 0)
    {
        printf("Invalid value!\n");
        return;
    }

    printf("%.2f kilograms is equal to %.2f pounds\n", weight, weight * converterValue);

}

void PoundsToKg(float converterValue)
{
    ScreenCleaner();
    float weight;

    printf("Enter the weight in pounds: ");
    if ((scanf("%f", &weight)) != 1 || weight < 0)
    {
        printf("Invalid value!\n");
        return;
    }

    printf("%.2f pounds is equal to %.2f kilograms\n", weight, weight / converterValue);

}

int main()
{
    const float converterValue = 2.20462f;
    int choice;

    printf("Weight conversion program.\n");
    printf("1. Kilograms to Pounds\n2.Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");

    if ((scanf("%d", &choice)) != 1 || choice < 1 || choice > 2)
    {
        printf("Invalid value!\n");
        return 1;
    }

    // if (choice == 1)
    // {
    //     KgToPounds(converterValue);
    // } else
    // {
    //     PoundsToKg(converterValue);
    // }

    switch (choice){
        case 1:
            KgToPounds(converterValue);
            break;
            
        case 2:
            PoundsToKg(converterValue);
            break;
        default:
            break;
    }

    return 0;
}