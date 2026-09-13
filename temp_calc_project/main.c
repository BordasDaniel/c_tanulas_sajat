#include <stdio.h>

void ScreenCleaner(void)
{
    printf("\033[H\033[J");
}

void CelsiusToFarenheit(float celsius)
{
    float farenheit = celsius * 1.8 + 32;
    printf("%.2fC is equal to %.2fF\n", celsius, farenheit);

}

void FarenhetiToCelsius(float farenheit)
{
    float celsius = (farenheit - 32) * ((float)5/9);
    printf("%.2fF is equal to %.2fC\n", farenheit, celsius);

}


int main()
{
    float value;
    int choice;

    printf("Temp. converter app\n");
    printf("1. Farenheit to Celsius\n2. Celsius to Farenheit\nPlease choose(1 or 2): ");

    if ((scanf("%d", &choice)) != 1 || choice < 1 || choice > 2)
    {
        printf("Invalid value!\n");
        return 1;
    }


    printf("Please give me the base value: ");
    if ((scanf("%f", &value)) != 1)
    {
        printf("Invalid value\n");
        return 1;
    }

    ScreenCleaner();

    switch (choice)
    {
    case 1:
        FarenhetiToCelsius(value);
        break;
    
    case 2:
        CelsiusToFarenheit(value);
        break;

    default:
        break;
    }

    return 0;
}