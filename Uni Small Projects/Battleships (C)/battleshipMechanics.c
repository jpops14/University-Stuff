#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "battleshipMechanics.h"
#include "battleshipsUI.h"

void init_maps(int map1[10][10],int map2[10][10],int ships[14])
{
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            map1[i][j]=14;
            map2[i][j]=14;
        }
    ships[0]=2;
    ships[1]=2;
    ships[2]=3;
    ships[3]=3;
    ships[4]=4;
    ships[5]=4;
    ships[6]=6;
    ships[7]=2;
    ships[8]=2;
    ships[9]=3;
    ships[10]=3;
    ships[11]=4;
    ships[12]=4;
    ships[13]=6;

}

bool place_ship(int map1[10][10],int row, int column, char orientation,int length, int ship)
{
    if(row<0||column<0||row>=10||column>=10)
        return false;

    if(orientation=='H')    //horizontal
    {
        if(column+length-1>=10)
            return false;
        for(int i=0; i<length; i++)
        {
            if(map1[row][column+i]!=14)
                return false;
        }
        for(int i=0; i<length; i++)
        {
            map1[row][column+i]=ship;
        }

        return true;
    }
    else if (orientation=='V')  //vertical
    {
        if(row+length-1>=10)
            return false;
        for(int i=0; i<length; i++)
        {
            if(map1[row+i][column]!=14)
                return false;
        }
        for(int i=0; i<length; i++)
        {
            map1[row+i][column]=ship;
        }

        return true;
    }
    else return false;
}

int attack(int map1[10][10],int row, int column)
{

    if(row<0||column<0||column>=10||row>=10)
    return -1;


    int target=map1[row][column];
    if (target>=0&&target<14)
        map1[row][column]=16;
    else if(target==14)
    {
        map1[row][column]=15;
    }
    else target=-1;
    return target;
}

void map_setup(int map1[10][10],int map2[10][10],int ships[14], int player)
{
  int a;
  char x,z;
  int y;
  bool correct;
  if (player==1)a=0;
    else a=7;
  for(int i=a; i<a+7; i++)
        {
            correct=0;
            while(correct==0)
            {
                display_game(map1,map2,player,24,24);
                display_request(2,i+1,ships[i]);
                ///wczytaj

                scanf("%c",&x);
                if(x=='Q') return;
                scanf("%d %c",&y,&z);
                fflush(stdin);


                correct=place_ship(map1,x-'A',y-1,z,ships[i],i);

                if(correct==0)
                {

                    display_game(map1,map2,player,24,24);
                    error_prompt();
                }
            }
        }
}


void new_game(int map1[10][10],int map2[10][10],int ships[14])
{


  init_maps(map1,map2,ships);

        switching_player(1);
        map_setup(map1,map2,ships,1);

        switching_player(2);
        map_setup(map2,map1,ships,2);
}

int make_move(int map1[10][10],int map2[10][10], int * health1, int * health2, int ships[14],int player, char * rx,int  *ry)
{
    char x;
    int y;
    int target=-1;
    while(target<0||target>14)
        {
            if(player==1)
                display_game(map1,map2,1,*health1,*health2);
            else display_game(map2,map1,2,*health2,*health1);
            display_request(1,0,0);
            //wczytaj
            scanf("%c",&x);
            if(x=='Q') return -5;
            scanf("%d",&y);
            fflush(stdin);
            if(player==1)
                target=attack(map2,x-'A',y-1);
            else target=attack(map1,x-'A',y-1);



            if(target<0||target>14)
            {
                if(player==1)
                display_game(map1,map2,1,*health1,*health2);
                else display_game(map2,map1,2,*health2,*health1);
                error_prompt();
            }
            else
            {
                if(target!=14)
                {
                ships[target]--;
                if(player==1)(*health2)--;
                else (*health1)--;
                }
                if(player==1)
                display_game(map1,map2,1,*health1,*health2);
                else display_game(map2,map1,2,*health2,*health1);
                display_target(target,ships);
            }

        }
        *rx=x;
        *ry=y;
        return target;
}

void start_turn(int map1[10][10],int map2[10][10], int health1, int health2, int ships[14],int round, int target,int player, char x,int y)
{
    switching_player(player);
        ///wyczysc
        if(round%2==1) player=1;
        else player=2;
        ///wyswietl mapy i raport
        if(player==1)
            display_game(map1,map2,1,health1,health2);
        else display_game(map2,map1,2,health2,health1);
        if(target>=0&&target<14)
        {

            if(ships[target]>0)display_raport(1,x,y);   ///enemy has hit our ship
            else display_raport(5,x,y);  ///enemy has sunken our ship

            }
        else if(target==14)
            display_raport(2,x,y);   ///enemy has missed
        else  if(round==1)
            display_raport(3,x,y);   ///battle is beginning
        else display_raport(4,x,y);   ///welcome back
}
