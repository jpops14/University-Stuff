#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "battleshipsUI.h"
#include "battleshipMechanics.h"
#include <conio.h>
#include "gamemaster.h"

void run_game(int round,int map1[10][10],int map2[10][10],int health1,int health2,int ships[14])
{

    int y=-1;
    char x='G';
    ///nowa gra
    if (round==0)
    {
        new_game(map1,map2,ships);
        round=1;
    }
    int player;
    if(round%2==1)player=1;
    else player=2;
    int target=-1;

    while(health1>0&&health2>0)
    {
        start_turn(map1,map2,health1,health2,ships,round,target,player,x,y);
        ///wyczysc
        ///oczekuj na komendy
        target=make_move(map1,map2,&health1,&health2,ships,player,&x,&y);
        if (target==-5)return;
        round++;
        if(player==2) player=1;
        else player=2;

    }

    if(health1==0)
    {
        win_banner(2);
    }
    else
    {
        win_banner(1);
    }
    return;
}




