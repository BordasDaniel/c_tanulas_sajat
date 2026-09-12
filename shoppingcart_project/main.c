#include <stdio.h>
#include <string.h>

void pufferClear()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int quantity;
    float price;
    char item[10];
    char currency = '$';

    printf("What would you like to buy? : ");
    fgets(item, sizeof(item), stdin);
    item[strlen(item) - 1] = '\0';

    printf("At what price? : ");
    scanf("%f", &price);
    pufferClear();
    
    printf("How many would you like? :");
    scanf("%d", &quantity);
    pufferClear();

    printf("You have ordered: %d %s/s at the price of %.2f%c\n", quantity, item, price*quantity, currency);


    return 0;
}