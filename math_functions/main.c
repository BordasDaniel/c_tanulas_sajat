#include <stdio.h>
#include <math.h>

int main()
{
    // All useful math functions.
    double x = 2.0;
    double y = 3.0;

    printf("x = %f\n", x);
    printf("y = %f\n", y);

    // Power function
    double power_result = pow(x, y);
    printf("x^y = %f\n", power_result);

    // Square root
    double sqrt_result = sqrt(x);
    printf("sqrt(x) = %f\n", sqrt_result);

    // Logarithm
    double log_result = log(x);
    printf("log(x) = %f\n", log_result);

    // Sine
    double sin_result = sin(x);
    printf("sin(x) = %f\n", sin_result);

    // Cosine
    double cos_result = cos(x);
    printf("cos(x) = %f\n", cos_result);

    // Tangent
    double tan_result = tan(x);
    printf("tan(x) = %f\n", tan_result);

    return 0;
}