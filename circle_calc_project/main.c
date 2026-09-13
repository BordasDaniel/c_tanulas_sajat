#include <stdio.h>
#include <math.h>

void puffer_cleaner()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    const double pi = M_PI;
    double radius;
    double area;
    double surface_area;
    double volume;

    printf("Give me the radius of your circle in cm: ");
    scanf("%lf", &radius);
    puffer_cleaner();


    area =  pi * pow(radius, 2);
    surface_area =  4* pi * pow(radius, 2);
    volume = (4.0/3) * pi * pow(radius, 3);

    printf("Area: %.4lfcm\n", area);
    printf("Surface Area: %.4lfcm^2\n", surface_area);
    printf("Volume: %.4lfcm^3\n", volume);



    return 0;
}