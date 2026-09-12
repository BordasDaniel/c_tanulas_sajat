#include <stdio.h>

int main()
{
    int age = 10;
    float price = 19.19;
    double pi = 3.141414;
    char currency = '$';
    char name[] = "Henrick Array";
    

    // Normal Data outputting
    printf("%d\n", age);
    printf("%f\n", price);
    printf("%lf\n", pi);
    printf("%c\n", currency);
    printf("%s\n", name);
    
    printf("----------------------\n");
    
    // Width (at least)

    int num1 = 1;
    int num2 = 10;
    int num3 = 100;
    
    printf("%3d\n", num1);
    printf("%3d\n", num2);
    printf("%3d\n", num3);

    /*
    Output:
      1
     10
    100

    If the digit does not have enough items, then it will show a space instead of it.
    */

    printf("%-4d\n", num1);
    printf("%-4d\n", num2);
    printf("%-4d\n", num3);

    /*
    Output: 
    1 . . .   
    10 . .
    100 .
    
    Each dot is a taken space for the digit because of the negative sign.

    */
   
    
    printf("%04d\n", num1);
    printf("%04d\n", num2);
    printf("%04d\n", num3);

    /*
    Each empty space will be filled with 0
    */

    int neg_num3 = -100;

    printf("%+d\n", num1);
    printf("%+d\n", num2);
    printf("%+d\n", neg_num3);

    /*
    Output:
    +1
    +10
    -100

    It either + or - depending whether its positive or negative.
    */


    // Precision

    printf("-------------\n");

    float price1 = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;

    printf("%.2f\n", price1);
    printf("%.1f\n", price2);
    printf("%.2f\n", price3);

    /*
    Output:
    19.99
    1.5
    -100.00

    %.precisionf (it rounds...)
    */

    // You can combine them.

    // Min 7 width with 2 precision
    printf("-------------\n");

    printf("%7.2f\n", price1);
    printf("%7.2f\n", price2);
    printf("%7.2f\n", price3);


    return 0;
}