#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#define SPACE 32
#define HL 196
#define VL 179
#define TT 194
#define LST 195
#define RST 180
#define BT 193
#define LT 218
#define RT 191
#define LB 192
#define RB 217
#define CROSS 197
#define BS 8
#define TOTCOLS 80
#define TOTROWS 25
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 5
#define DIM 7

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void makeLayout()
{
    int col;
    int row;
    int ctr1;
    int ctr2;
    int ctr3;
    int ctr4;
    int ctr5;
    col = 30;
    row = 8;
    gotoxy(col,row);
    printf("%c",LT);
    for(ctr1=0;ctr1<40;ctr1++)
    {
        printf("%c",HL);
    }
    printf("%c%c",BS,RT);
    row+=1;
    for(ctr2=0;ctr2<2;ctr2++)
    {
        gotoxy(col,row);
        printf("%c",VL);
        for(ctr3=0;ctr3<39 ;ctr3++)
        {
          printf("%c",SPACE);
        }
        printf("%c",VL);
        row++;
    }
    gotoxy(col,row);
    printf("%c",LST);
    for(ctr4=0;ctr4<40;ctr4++)
    {
        printf("%c",HL);
    }
    printf("%c%c",BS,RST);

}

int main()
{

    makeLayout();
    return 0;
}
