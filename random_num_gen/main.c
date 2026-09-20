#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("%d\n", rand()); // Always gives the same value back. 
    
    srand(time(NULL)); // This generates the seed for the random number. Without this line you get the same output.
    // The random number is based on OS and Compiler it can vary.
    
    printf("%d\n", rand());
    printf("%d\n", RAND_MAX);


    int randomnum = (rand() % 2) + 1; // 1 or 2
    printf("%d\n", randomnum);

    int min = 50;
    int max = 100;

    int randomnum1 = (rand() % (max - min + 1) + min);
    printf("%d\n", randomnum1);

    return 0;
}
