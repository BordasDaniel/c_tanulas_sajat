#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// T = tie, X = player 1, O = player 2
typedef enum {
    EMPTY, X, O, T
} PlayerSymbol;

void ScreenCleaner(void)
{
    printf("\033[H\033[J");
}

void BufferClearer(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


// Writes the latest game to a txt file with date
void GameFileWriter(PlayerSymbol pMatrix[3][3], PlayerSymbol winner)
{
    FILE* file = fopen("game_results.txt", "a");
    time_t rawtime = 0;
    struct tm* pTime = NULL;
    time(&rawtime);
    pTime = localtime(&rawtime);
    

    if(file == NULL)
    {
        printf("Error opening file!\n");
        return; // Exit the function if the file cannot be opened
    }
    fprintf(file, "Game played on: %02d-%02d-%04d %02d:%02d:%02d\n", pTime->tm_mday, pTime->tm_mon + 1, pTime->tm_year + 1900, pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
    fprintf(file, "Game result: %s\n", winner == X ? "Player X wins" : winner == O ? "Player O wins" : "It's a tie");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            fprintf(file, "%c ", pMatrix[i][j] == X ? 'X' : pMatrix[i][j] == O ? 'O' : '.');
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n----------------------------------------\n");
    fclose(file);

    printf("\nGame result saved to game_results.txt\n");
}


void MatrixPrinter(PlayerSymbol pMatrix[3][3])
{
    printf("Current game state:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%c ", pMatrix[i][j] == X ? 'X' : pMatrix[i][j] == O ? 'O' : '.');
        }
        printf("\n");
    }
}

PlayerSymbol WinnerDecider(PlayerSymbol pMatrix[3][3])
{
    // Row check
    for(int i = 0; i < 3; i++)
    {
        if(pMatrix[i][0] == pMatrix[i][1] && pMatrix[i][1] == pMatrix[i][2] && pMatrix[i][0] != EMPTY)
        {
            return pMatrix[i][0];
        }
    }

    // Column check
    for(int i = 0; i < 3; i++)
    {
        if(pMatrix[0][i] == pMatrix[1][i] && pMatrix[1][i] == pMatrix[2][i] && pMatrix[0][i] != EMPTY)
        {
            return pMatrix[0][i];
        }
    }

    // Cross check
    if(pMatrix[0][0] == pMatrix[1][1] && pMatrix[1][1] == pMatrix[2][2] && pMatrix[0][0] != EMPTY)
    {
        return pMatrix[0][0];
    }
    if(pMatrix[0][2] == pMatrix[1][1] && pMatrix[1][1] == pMatrix[2][0] && pMatrix[0][2] != EMPTY)
    {
        return pMatrix[0][2];
    }

    return EMPTY; // Nincs még nyertes
}

bool IsMatrixFull(PlayerSymbol pMatrix[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(pMatrix[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}

void PlayerTurn(PlayerSymbol pMatrix[3][3], PlayerSymbol player)
{
    int row, col;
    do
    {
        ScreenCleaner();
        MatrixPrinter(pMatrix);

        printf("Player %c's turn:\n", player == X ? 'X' : 'O');
        printf("Enter row (0-2): ");
        if(scanf("%d", &row) != 1)
        {
            BufferClearer();
            printf("Invalid input! Please enter a number between 0 and 2.\n");
            continue;
        }

        printf("Enter column (0-2): ");
        if(scanf("%d", &col) != 1)
        {
            BufferClearer();
            printf("Invalid input! Please enter a number between 0 and 2.\n");
            continue;
        }

    } while(row < 0 || row > 2 || col < 0 || col > 2 || pMatrix[row][col] != EMPTY);
    
    pMatrix[row][col] = player;
}

PlayerSymbol FirstPlayerDecider(void)
{
    srand((unsigned int)time(NULL));
    return rand() % 2 == 0 ? X : O;
}

void GameLogic(PlayerSymbol pMatrix[3][3], PlayerSymbol nextPlayer)
{
    bool isGameOver = false;
    PlayerSymbol winner = EMPTY;
    bool isItFull = false;

    while(!isGameOver)
    {
        ScreenCleaner();
        MatrixPrinter(pMatrix);
        PlayerTurn(pMatrix, nextPlayer);
        
        winner = WinnerDecider(pMatrix);
        isItFull = IsMatrixFull(pMatrix);

        if(winner != EMPTY)
        {
            ScreenCleaner();
            MatrixPrinter(pMatrix);
            printf("Player %c wins!\n", winner == X ? 'X' : 'O');
            isGameOver = true;
        }
        else if(isItFull)
        {
            ScreenCleaner();
            MatrixPrinter(pMatrix);
            printf("It's a tie!\n");
            isGameOver = true;
        }
        else
        {
            nextPlayer = (nextPlayer == X) ? O : X;
        }
    }
    GameFileWriter(pMatrix, winner);
}

void Game(void)
{
    PlayerSymbol matrix[3][3] = {EMPTY};
    PlayerSymbol firstPlayer = FirstPlayerDecider();
    GameLogic(matrix, firstPlayer);
}

int main(void)
{
    Game();
    return 0;
}