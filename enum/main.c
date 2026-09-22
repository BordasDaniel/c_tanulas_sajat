#include <stdio.h>

typedef enum{
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
}Day;

typedef enum{
    SUCCESS, FAILURE, PENDING
}Status;


void ConnectStatus(Status status)
{
    switch (status)
    {
        case SUCCESS:
            printf("Connection was successful!\n");
            break;
        case FAILURE:
            printf("Could not connect!\n");
            break;
        case PENDING:
            printf("Connecting...\n");
            break;
        default:
            break;
    }
}

int main()
{
    //enum = user defined data type that consists of a set of named integer constants

    Day today = MONDAY;

    printf("%d\n", today);
    if (today == SUNDAY || today == SATURDAY)
    {
        printf("It's the weekend!\n");
    }
    else
    {
        printf("It's a weekday!\n");
    }

    Status status = SUCCESS;
    ConnectStatus(status);


    return 0;
}