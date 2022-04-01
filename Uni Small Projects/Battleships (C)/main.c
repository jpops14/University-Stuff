#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gamemaster.h"
#include "menu.h"
#include <stdbool.h>
#include "battleshipsUI.h"

int main()
{
    while(true)
    {
    display_menu();
    int map1[10][10];
    int map2[10][10];
    int ships[14];
    int health1=24;
    int health2=24;
    int round=0;
    char command='G';
    while(command!='N'&&command!='H'&&command!='Q')
    {
        scanf("%c",&command);
        fflush(stdin);
    }
    if(command=='N')
    run_game(round,map1,map2,health1,health2,ships);
    else if(command=='H')
    show_help();
    else if(command=='L')
        continue;
    else if(command=='Q')
        break;
    }
    return 0;
}
