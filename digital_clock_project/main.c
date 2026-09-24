#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>



int main()
{
    time_t rawtime = 0;
    struct tm* pTime = NULL;

    printf("Digital Clock\n");

    while (true)
    {
        time(&rawtime);
        
        pTime = localtime(&rawtime);
        printf("\r%02d:%02d:%02d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
        fflush(stdout);

        sleep(1);
    }
    
    

    return 0;
}