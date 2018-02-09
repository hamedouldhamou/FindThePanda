#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "functions.h"

void game()
{
    StateOfGame state = {0};
    state.end_game = 0;
    state.win = 0;
    state.turn = 1;

    printf("Enter the name of player 1> ");
    scanf("%s", state.NamePlayer1);
    printf("Enter the name of player 2> ");
    scanf("%s", state.NamePlayer2);

    if (!LoadGame(&state))
        exit(EXIT_FAILURE);

    while (!state.end_game)
    {
        system("cls");

        int i, j;
        for (i = 0; i< NB_BLOCS_HIGHT; i++)
        {
            for (j =0; j<NB_BLOCS_WIDTH; j++)
            {
                if (state.PositionPlayer1.x == i && state.PositionPlayer1.y == j)
                {

                    if(state.capes_player1 > 0)
                {
                    state.capes_player1--;
                    putchar(' ');

                }
                else
                    putchar('1');

               }
           else if (state.PositionPlayer2.x == i && state.PositionPlayer2.y == j)
           {

                if (state.capes_player2 > 0)
                {
                    state.capes_player2--;
                    putchar(' ');
                }
                else
                    putchar('2');
           }
           else if (state.PositionPanda.x == i && state.PositionPanda.y == j)
            {

                if (state.capes_panda > 0)
                {
                    state.capes_panda--;
                    putchar(' ');
                }
                else
                    putchar('P');
           }
           else if (state.Posions.x == i && state.Posions.y == j)
            putchar('F');
           else if (state.capes.x ==i && state.capes.y == j)
            putchar('C');
           else
            putchar(state.map[i][j]);

        }
    }
char chaine [4];

if (state.turn == 1)
 printf("Player 1: %s Potions(%d) Capes(%d)>", state.NamePlayer1, state.Posions_Player1, state.capes_player1);
else if (state.turn == 2)
 printf("Player 2: %s Potions(%d) Capes(%d)>", state.NamePlayer2, state.Posions_Player2, state.capes_player2);
scanf("%s", &chaine);
fflush(stdin);

char direction = tolower(chaine[0]);
int movement = chaine[1] - 48;
if (direction == 'q')
    state.end_game = 1;

    Pos* CurrentPlayer = NULL;
    int* PosionCurrent = NULL;

    if (state.turn == 1)
    {
        CurrentPlayer = &state.PositionPlayer1;
        PosionCurrent = &state.Posions_Player1;
        state.turn =2;

    }
    else if (state.turn == 2)
    {
        CurrentPlayer = &state.PositionPlayer2;
        PosionCurrent = &state.Posions_Player2;
        state.turn =1;
    }
    if (direction == 'u')
    {
        if (*PosionCurrent >0)
        {
        *PosionCurrent--;
        CurrentPlayer-> x-=movement;
        }
        else if (!collision(&state, CurrentPlayer->x - movement, CurrentPlayer->y))
            CurrentPlayer-> x-= movement;

    }
     if (direction == 'd')
    {
        if (*PosionCurrent >0)
        {
        *PosionCurrent--;
        CurrentPlayer-> x+=movement;
        }
        else if (!collision(&state, CurrentPlayer->x + movement, CurrentPlayer->y))
            CurrentPlayer-> x+= movement;

    }
     if (direction == 'l')
    {
        if (*PosionCurrent >0)
        {
        *PosionCurrent--;
        CurrentPlayer-> y-=movement;
        }
        else if (!collision(&state, CurrentPlayer->x , CurrentPlayer->y - movement))
            CurrentPlayer-> y-= movement;

    }
     if (direction == 'r')
    {
        if (*PosionCurrent >0)
        {
        *PosionCurrent--;
        CurrentPlayer-> y+=movement;
        }
        else if (!collision(&state, CurrentPlayer->x , CurrentPlayer->y + movement))
            CurrentPlayer-> y+= movement;

    }

    if (state.PositionPlayer1.y == state.PositionPanda.y && state.PositionPlayer1.x == state.PositionPanda.x)
    {
      state.win = 1;
      state.end_game = 1;
    }

    if (state.PositionPlayer2.y == state.PositionPanda.y && state.PositionPlayer2.x == state.PositionPanda.x)
    {
      state.win = 2;
      state.end_game = 1;
    }

    if (state.PositionPlayer1.y == state.Posions.y && state.PositionPlayer1.x == state.Posions.x)
    {
        state.Posions_Player1 =1;
        state.Posions.x = -1;
        state.Posions.y = -1;
    }
     if (state.PositionPlayer2.y == state.Posions.y && state.PositionPlayer2.x == state.Posions.x)
    {
        state.Posions_Player2 =1;
        state.Posions.x = -1;
        state.Posions.y = -1;
    }
    else if (state.PositionPanda.y == state.Posions.y && state.PositionPanda.x == state.Posions.x)
    {
        state.Posions_Player1 =4;
        state.Posions.x = -1;
        state.Posions.y = -1;
    }

    int x=0, y=0;
    do
    {
        x = state.PositionPanda.x;
        y = state.PositionPanda.y;

        int direction = rand()%4;

        switch(direction)
        {
         case 0: y+=2;break;
         case 1: y-=2 ; break;
         case 2: x+=2 ; break;
         case 3 : x-=2; break;

         default: y++;break;

        }

    } while (collision(&state, x, y));
    state.PositionPanda.x = x;
    state.PositionPanda.y = y;
}
 if (state.win > 0)
 {
   system("cls");
   FILE *file = NULL;

   if (state.win == 1)
    file = fopen("text/J1 Gagne.txt","r");

   else if (state.win == 2)
    file = fopen("text/J2 Gagne.txt","r");

   char Win[512];

   if (file != NULL)
   {
        while (fgets(Win, 512, file) !=NULL)
        {
           Sleep(100);
           printf("%s",Win);
        }
        fclose(file);
        system("pause");
   }
 }
}
