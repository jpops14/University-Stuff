#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include <windows.h>
#include "battleshipsUI.h"
void display_menu()
{
    ///save console default data
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    clear_screen();
    for(int i=1;i<=80;i++)
        printf("=");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);


      printf("\n      ______  ___ _____ _____ _      _____ _____ _   _ ___________  _____\n");
        printf("      | ___ \\/ _ \\_   _|_   _| |    |  ___/  ___| | | |_   _| ___ \\/  ___|\n");
        printf("      | |_/ / /_\\ \\| |   | | | |    | |__ \\ `--.| |_| | | | | |_/ /\\ `--. \n");
        printf("      | ___ \\  _  || |   | | | |    |  __| `--. \\  _  | | | |  __/  `--. \\ \n");
        printf("      | |_/ / | | || |   | | | |____| |___/\\__/ / | | |_| |_| |    /\\__/ / \n");
        printf("      \\____/\\_| |_/\\_/   \\_/ \\_____/\\____/\\____/\\_| |_/\\___/\\_|    \\____/  \n \n");

     SetConsoleTextAttribute(hConsole, saved_attributes);

    for(int i=1;i<=80;i++)
        printf("=");
      printf("\n\n                           Type N to start a new game\n \n");
      ///printf("                           Type L to load a saved game\n \n");
      printf("                             Type H to to show help\n \n");
      printf("                                 Type Q to quit\n");

    ////17
}


void show_help()
{

    clear_screen();
    char ender='Q';
    while(ender!='M')
    {
    for(int i=1;i<=80;i++)printf("=");
    printf("\n\n");
    printf("Battleships is a strategic guessing game for 2 players.\n");
    printf("Game begins with two player placing their ships on their respective grids.\n");
    printf("Players are not allowed to see their oponent's grid.\n");
    printf("After placing their ships, players take turns guessing locations of oponent's\n");
    printf("ships. If they guess correctly, enemy loses one fleet strength point and\n");
    printf("the attacked ship module is marked as destroyed. Players can't attack any\n");
    printf("postion more than once. Game ends when one of the player loses all of his \n");
    printf("fleet. Players choose coordinates they want to attack by typing a letter \n");
    printf("describing the row and a number describing the column.\n");
    printf("While placing ships, players also need to type a letter desribing how the ship\n");
    printf("will be orientated - either extending to the right of chosen coordinates\n");
    printf("(horizontally) or extending downwards from chosen coordinates (vertically)");
    printf("\n");



    printf("Type M to return to menu.\n\n");
    for(int i=1;i<=80;i++)printf("=");
    printf("\n");
    scanf("%c",&ender);
   fflush(stdin);
    }
   return;
}
