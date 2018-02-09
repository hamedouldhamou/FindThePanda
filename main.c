#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

#include "menu.h"

int main(int argc, char *argv[])
{
    srand(time(0));

    // Modifier la couleur de la console
    system("COLOR 02");

    // Redimensione la console a la taille du niveau
    system("MODE CON COLS=80 LINES=17");

    logo();

    menu();
}
