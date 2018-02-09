#ifndef FUNCTION_H
#define FUNCTION_H

#define NB_BLOCS_HIGHT 16
#define NB_BLOCS_WIDTH 80
struct Pos
{
    int x,y;
};

typedef struct Pos Pos;

struct StateOfGame
{
    Pos PositionPlayer1;
    Pos PositionPlayer2;
    Pos PositionPanda ;

    int win;
    int end_game;
    int turn;

    Pos Posions;
    int Posions_Player1;
    int Posions_Player2;
    int Posions_panda;

    Pos capes;
    int capes_player1;
    int capes_player2;
    int capes_panda;

    char map[NB_BLOCS_HIGHT][NB_BLOCS_WIDTH];
    char NamePlayer1[255];
    char NamePlayer2[255];
};

typedef struct StateOfGame StateOfGame;
int LoadGame(StateOfGame* state);
int collision(StateOfGame* state, int x, int y );

#endif // FUNCTION_H
