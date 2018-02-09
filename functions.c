#include <stdlib.h>
#include <stdio.h>

#include "functions.h"

int LoadGame(StateOfGame* state)
{
    FILE* file = NULL;

    file = fopen("niveaux.txt", "r");

    if (file == NULL)
        return 0;
    fseek(file,0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    char* ligneFile = malloc(sizeof(char)*size);

    int t = 0, i = 0, j=0;
    for (t = 0; t< size; t++)
        ligneFile[t] = getc(file);
    for (t = 0; t< size; t++)
    {
        switch (ligneFile[t])
        {
        case 'M':
            state -> map[i][j] = 219;
            j++;
            break;
        case '1' :
            state -> map[i][j] = ' ';
            state -> PositionPlayer1.x = i;
            state -> PositionPlayer1.y = j;
            j++;
            break;
        case '2' :
            state -> map[i][j] = ' ';
            state -> PositionPlayer2.x = i;
            state -> PositionPlayer2.y = j;
            j++;
            break;
        case 'P' :
            state -> map[i][j] = ' ';
            state -> PositionPanda.x = i;
            state -> PositionPanda.y = j;
            j++;
            break;
        case 'F':
            state -> map[i][j] = ' ';
            state -> Posions.x = i;
            state -> Posions.y = j;
            j++;
        case 'C':
            state -> map [i][j] = ' ';
            state -> capes.x = i;
            state -> capes.y = j;
            j++;
            break;
         case '\n':
            i++;
            j = 0;
            break;
         default :
            state -> map[i][j] = ' ';
            j++;
        }
        }
    fclose(file);
    free(ligneFile);
    return 1;
    }
int collision (StateOfGame * state, int x, int y)
{

    if (x < 0 || y < 0)
        return 1;

    if (state-> map[x][y] == -37)
        return 1;

    if(x ==state->PositionPlayer1.x && y== state-> PositionPlayer1.y )
        return 1;

    if (x==state->PositionPlayer2.x && y==state->PositionPlayer2.y)
        return 1;

    return 0;
    }


