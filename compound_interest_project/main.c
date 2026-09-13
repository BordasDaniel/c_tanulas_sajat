#include <stdio.h>
#include <math.h>


int main()
{
    double principal;
    double interest_rate;
    int years;
    int times;
    double overall;

    printf("Enter the principal (P): ");
    scanf("%lf", &principal);

    printf("Enter the interest rate (r): ");
    scanf("%lf", &interest_rate);

    printf("Enter the # of years (t): ");
    scanf("%d", &years);

    printf("Enter # of times compounded per year (n): ");
    scanf("%d", &times);

    overall = principal * pow((1.0 + (interest_rate / 100.0) / times), years * times);
    printf("After %d years, the total will be $%.2f\n", years, overall);


    return 0;
}