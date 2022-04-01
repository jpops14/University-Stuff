#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "battleshipsUI.h"
#include <windows.h>

void wait_time(int x)
{
    Sleep(x);
}

void clear_screen()
{
    system("cls");
}

void display_raport(int type,char x,int y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    ///

    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=12; i++)
        printf(" ");

    if   (type==1)
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("          Enemy has hit our ship at: %c %d \n",x,y);
        SetConsoleTextAttribute(hConsole,saved_attributes);
    }
    else if (type==2)
    {
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
        printf("         Enemy has missed at: %c &d \n",x,y);
        SetConsoleTextAttribute(hConsole,saved_attributes);
    }
    else if (type==3)
    {
            printf("                   The battle has begun\n");
    }
    else if (type==4)
    {
        printf("                  Game loaded succesfully\n");
    }
    else
    {   SetConsoleTextAttribute(hConsole,FOREGROUND_RED);
        printf("       Enemy has sunk our ship at: %c %d \n",x,y);
        SetConsoleTextAttribute(hConsole,saved_attributes);
    }
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");

    wait_time(3000);
}

void display_target(int target,int ships[14])
{



    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=12; i++)
        printf(" ");

    if   (target==14)
    {
        printf("          We have missed the enemy\n");
    }
    else if(ships[target]>0) printf("          Confirmed hit on enemy ship\n");
    else printf("              Enemy ship is hit and sinking\n");


    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    wait_time(3000);
}

void switching_player(int player)
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    ///
    clear_screen();

    for(int i=1; i<=7; i++)
        printf("\n");
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=26; i++)
        printf(" ");

    SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
    if   (player==1)
        printf(" It is time for PLAYER 1's turn!\n");
    else printf(" It is time for PLAYER 2's turn!\n");

    SetConsoleTextAttribute(hConsole,saved_attributes);

    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for(int i=1; i<=6; i++)
        printf("\n");

    wait_time(5000);
}

void win_banner(int player)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    clear_screen();

    for(int i=1; i<=7; i++)
        printf("\n");
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=26; i++)
        printf(" ");

    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);

    if   (player==1)
        printf("PLAYER 1 has achieved victory!\n");
    else printf("PLAYER 2 has achieved victory!\n");

    SetConsoleTextAttribute(hConsole,saved_attributes);
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for(int i=1; i<=6; i++)
        printf("\n");

   wait_time(5000);
}

void top_banner(int player)
{
    ///top banner
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=36; i++)
        printf(" ");

    if   (player==1)
        printf("PLAYER 1\n");
    else printf("PLAYER 2\n");

    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
}

void object(int x,int mode)
{
       ///backup console data
    ///save console default data
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    if(mode==1)
    {
        if(x<14)
        {///ship
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("*");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        else if(x==15)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("O");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }

        else if(x==16)
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("X");
            SetConsoleTextAttribute(hConsole, saved_attributes);
        }
        else printf(" ");
    }
    else if(mode==2)
    {
        if (x==15)  ///miss
             {
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("O");
            SetConsoleTextAttribute(hConsole, saved_attributes);
             }
        else if (x==16)
             {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("X");
            SetConsoleTextAttribute(hConsole, saved_attributes);
             }
        else printf("?");
    }
    else printf("!");
}

void display_game(int friendly[10][10],int enemy[10][10],int player, int playerhealth,int enemyhealth)
{
    clear_screen();
    ///top banner
    top_banner(player);

    printf("   1 2 3 4 5 6 7 8 9 10  ||                          ||     1 2 3 4 5 6 7 8 9 10\n");

    for(int i=0; i<10; i++)
    {
        ///friendly map
        printf("%c  ",i+'A');
        for(int j=0; j<10; j++)
        {
            object(friendly[i][j],1);
            ///wypisz symbol

            printf(" ");
        }
        printf("  ");

        ///middle UI
        printf("||");
        if(i==3)
        {
            printf("  Your fleet strength: ");
            if(playerhealth<10)printf(" ");
            printf("%d ",playerhealth);
        }
        else if(i==4)
        {
            printf(" Enemy fleet strength: ");
            if(enemyhealth<10)printf(" ");
            printf("%d ",enemyhealth);
        }
        else printf("                          ");


        printf("||");
        ///enemy map
        printf("  %c  ",i+'A');
        for(int j=0; j<10; j++)
        {
            object(enemy[i][j],2);
            printf(" ");
        }
        printf("\n");

    }

}

void display_request(int type,int arg1,int arg2)
{
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=8; i++)
        printf(" ");

    if   (type==1)
        printf("    Please enter desired attack coordinates: <A-J> <1-10> \n");
    else printf("Choose position for your %d. ship (length:%d): <A-J> <1-10> H/V  \n",arg1,arg2);

    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
}

void error_prompt()
{
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;
    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    for (int i=1; i<=12; i++)
        printf(" ");

    SetConsoleTextAttribute(hConsole,FOREGROUND_RED);

    printf("        Incorrect input, please try again\n");

    SetConsoleTextAttribute(hConsole,saved_attributes);

    for(int i=1; i<=80; i++)
        printf("=");
    printf("\n");
    wait_time(3000);
}


