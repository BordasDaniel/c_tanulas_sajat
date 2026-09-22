#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


typedef char* string;

#pragma region Game

string RandomChooser(string* list)
{
    int index = rand() % 3;
    return list[index];
}

bool ValidatorChecker(string choice, string* list)
{
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(choice, list[i]) == 0)
            return true;
    }
    return false;
}

bool Determiner(string choice, string computerChoice)
{
    if (strcmp(choice, computerChoice) == 0)
    {
        printf("It's a tie!\n");
        return true;
    }

    if ((strcmp(choice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0) ||
        (strcmp(choice, "paper") == 0 && strcmp(computerChoice, "rock") == 0) ||
        (strcmp(choice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0))
    {
        printf("You win!\n");
        return true;
    }
    else
    {
        printf("Computer wins!\n");
        return false;
    }
}


#pragma endregion Game



int main()
{
    srand(time(NULL)); // seed
    string signals[] = {"rock", "paper", "scissors"};
    string* pSignal = signals; // Pointer to the array.
    char playerChoice[20];

    printf("Welcome to Rock, Paper, Scissors!\n");
    printf("Enter your choice (rock, paper, or scissors): ");

    if (fgets(playerChoice, sizeof playerChoice, stdin) == NULL) return 1;
    playerChoice[strcspn(playerChoice, "\r\n")] = '\0';

    if (!ValidatorChecker(playerChoice, pSignal))
    {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    string computerChoice = RandomChooser(pSignal);
    printf("Computer chose: %s\n", computerChoice);

    Determiner(playerChoice, computerChoice);


    return 0;
}