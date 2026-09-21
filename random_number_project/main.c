#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


void ScreenCleaner(void)
{
    printf("\033[H\033[J");
}

void BufferCleaner(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool Guessed(int toGuess, int guess)
{
    if (toGuess == guess)
        return true;

    if (toGuess > guess)
        printf("The number is bigger than yours!\n");
    else
        printf("The number is smaller than yours!\n");

    return false;
}


int RandomNumberGen(int min, int max)
{
    return (rand() % (max - min +1)) + min;
}



int main()
{
    int min;
    int max;
    int guess;
    int randomNumb;
    bool isGuessed = false;

    srand(time(NULL));

    printf("Random Number Guessing Game:\n");
    printf("Enter the minimum value: ");
    if (scanf("%d", &min) != 1)
        return 1;

    printf("Enter the maximum value: ");
    if (scanf("%d", &max) != 1 || min > max)
    {
        printf("Invalid range.\n");
        return 1;
    }

    randomNumb = RandomNumberGen(min, max);
    printf("Your number has been generated!\nPress Enter to start the game!\n");
    BufferCleaner();
    getchar();

    do
    {
        ScreenCleaner();
        printf("Give me your guess: ");
        if (scanf("%d", &guess) != 1)
        {
            printf("Please enter a whole number.\n");
            BufferCleaner();
            continue;
        }

        isGuessed = Guessed(randomNumb, guess);
        if (!isGuessed)
        {
            printf("Press Enter to try again...\n");
            BufferCleaner();
            getchar();
        }
    } while (!isGuessed);
    
    printf("Congrats, you have guessed the number: %d\n", randomNumb);




    return 0;
}