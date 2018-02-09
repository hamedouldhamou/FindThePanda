#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "menu.h"
#include "game.h"

void credit()
{
    FILE *file = NULL;
    file = fopen("text/credit.txt","r");
    char credit [512];
    if (file != NULL)
    {
        while(fgets(credit,512,file) !=NULL)
        {
            Sleep(100);
            printf("%s", credit);
        }
        fclose(file);
        system("pause");
    }
}

void logo()
{
   FILE *file = NULL;
    file = fopen("text/CESI EXIA.txt","r");
    char credit[512];
    if(file != NULL)
    {
        while(fgets(credit, 512, file)!=NULL)
        {
            Sleep(100);
            printf("%s", credit);
        }
        fclose(file);
        system("pause");
    }
}

void menu()
{
     FILE *file = NULL;
  int ActualChar = 0;
  file = fopen("text/menu.txt", "r");

  if (file != NULL)
  {
    while (1)
  {
      system("cls");
      rewind(file);
      ActualChar = fgetc(file);
      while (ActualChar != EOF)
      {
        putchar(ActualChar);
        ActualChar = fgetc(file);
      }
      int choice = 0;
      printf("Chose an option >");
      scanf("%d", &choice);
      fflush(stdin);
      switch(choice)
      {
      case 1:
        system("cls");
        game();
        break;

      case 2:
        system("cls");
        credit();
        break;

      case 3 :
        exit(0);
        break;

      }

      }
  }
}
