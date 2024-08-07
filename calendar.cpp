#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;

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
int isLeap(int year)
{
    return ((year%4==0 && year%100!=0)|| year%400==0)? 1 : 0;
}
int DayOfWeek( int y, int m, int d )
{
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
y -= m < 3;
return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
void cleaner()
{
    int row;
    int col;
    int ctr;
    int week;
    col = (TOTCOLS-((DIM*WIDTH)+(DIM+1)))/2;
    row = (TOTROWS - (DIM+(DIM+1)))/2;
    col+=3;
    row+=3;
    for (week = 0; week < 6; week ++)
    {

    for(ctr = 0; ctr < DIM; ctr ++)
    {
     gotoxy(col + (ctr * (WIDTH+1)) , row);
     cout<<"  ";
    }
    row+=2;
    }

}
void makeCalendar(int month,int year)
{
    int dates_of_months[] = {0,31,28,31,30,31,30,\
    31,31,30,31,30,31};
    char *monthName [] = {"","January","February","March","April",\
    "May","June","July","August","September","October","November","December"};
    int col;
    int row;
    int date;
    int day;
    col = (TOTCOLS-((DIM*WIDTH)+(DIM+1)))/2;
    row = (TOTROWS - (DIM+(DIM+1)))/2;
    col+=3;
    row+=3;
    gotoxy(30,3);
    cout<<setw(9)<<monthName[month]<<","<<year;
    cleaner();
    if(isLeap(year) == 1)
    {
        dates_of_months[2] = 29;
    }
    else
    {
        dates_of_months[2] = 28;
    }
    for(date=1,day = DayOfWeek(year,month,1);date<=dates_of_months[month];date++)
    {
        gotoxy(col + (day*(WIDTH+1)),row );
        cout<<date;
        day++;
        if(day == DIM)
        {
            row+=2;
            day=0;
        }
    }

}
void colHeading()
{
    char* days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int row;
    int col;
    int ctr;
    col = (TOTCOLS-((DIM*WIDTH)+(DIM+1)))/2;
    row = (TOTROWS - (DIM+(DIM+1)))/2;
    col+=2;
    row+=1;
    for(ctr=0;ctr<DIM;ctr++)
    {
        gotoxy(col+(ctr*(WIDTH+1)),row);
        cout<<days[ctr];
    }

}

void makelayout()
{
  int col;
  int row;
  int ctr1;
  int ctr2;
  int ctr3;
  int ctr4;
  int ctr5;
  col = (TOTCOLS - ((WIDTH * DIM) + (DIM+1)))/2;
  row = (TOTROWS -  (DIM+(DIM+1)))/2;
  gotoxy(col,row);
  cout<<char(LT);
  for(ctr2=0;ctr2<DIM;ctr2++)
  {
   for(ctr1=0;ctr1<WIDTH;ctr1++)
   cout<<char(HL);
   cout<<char(TT);
  }
  cout<<char(BS)<<char(RT);
//first line ends here
  for(ctr3=0;ctr3<DIM;ctr3++)
  {
    row+=1;
    gotoxy(col,row);
    for(ctr4=0;ctr4<=DIM;ctr4++)
    {
      cout<<char(VL);
      for(ctr5=0;ctr5<WIDTH;ctr5++)
      {
         cout<<char(SPACE);
      }
    }
    row+=1;
    gotoxy(col,row);
    cout<<char(LST);
    for(ctr2=0;ctr2<DIM;ctr2++)
    {
        for(ctr1=0;ctr1<WIDTH;ctr1++)
           {
               cout<<char(HL);
           }
      cout<<char(CROSS);

    }
    cout<<char(BS)<<char(RST);
  }
//bottom line starts here
    gotoxy(col,row);
    cout<<char(LB);
   for(ctr1=0;ctr1<DIM;ctr1++)
   {
      for(ctr2=0;ctr2<WIDTH;ctr2++)
       {
         cout<<char(HL);
       }
     cout<<char(BT);
   }
   cout<<char(BS)<<char(RB);

}
int main()
{
    int month;
    int year;
    int key;
    cin>>month;
    cin>>year;
    makelayout();
    colHeading();
    do
    {
        makeCalendar(month,year);
        key=getch();
        switch(key)
        {
            case LEFT: month-=1; break;
            case RIGHT: month+=1; break;
            case UP: year-=1; break;
            case DOWN: year+=1; break;
        }
        if(month>12)
        {
            month =1;
            year+=1;
        }
        else if(month<1)
        {
            month = 12;
            year-=1;
        }

    }while(key!=27);

    return 0;
}
