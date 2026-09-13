#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// student = $9
// senior $8
// student + senior = $7

int TicketCalculator(float price, bool isStudent, bool isSenior)
{
    if(isStudent)
    {
        if(isSenior) return 7; // Senior + student

        return 9; // Only student
    }

    if (isSenior) return 8; // senior only

    return price;
}

void BufferCleaner(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


int main()
{
    const float price = 10.00f;
    bool isStudent = false;
    bool isSenior = false;
    char choice;

    printf("Ticket calculator\n");
    printf("Welcome!\nAre you a student? (y/n): ");

    scanf("%c", &choice);
    BufferCleaner();

    if (tolower(choice) == 'y') isStudent = true;
    else if (tolower(choice) != 'n') return 1;

    choice = '\0';

    printf("Are you a senior? (y/n): ");
    scanf("%c", &choice);
    BufferCleaner();

    if (tolower(choice) == 'y') isSenior = true;
    else if (tolower(choice) != 'n') return 1;

    printf("The price of your ticket is: $%d\n", TicketCalculator(price, isStudent, isSenior));


    return 0;


}