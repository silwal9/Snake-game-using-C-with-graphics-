#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <graphics.h>

void initialise();
void move();
void points();
void body();

int height=480,width=640;
int x,y;
int fruitx,fruity;            //snake coordinates
int gameover;
int dir;                //move flag
int score;
int tailx[100],taily[100];         //body coordinages


int main()
{
int i,k;
int gd=0,gm;
char driver[]="";
char end,scprint[128];
initgraph(&gd,&gm,driver);
label3:

initialise();
while (1)
{
cleardevice();
bar(70,0,640,10);
bar(0,0,10,480);
bar(630,10,640,480);
bar(10,470,640,480);

sprintf(scprint,"SCORE=%d",score);
outtextxy(1,1,scprint);

            bar(fruitx,fruity,fruitx+10,fruity+10);         //fruit coordinate

            bar(x,y,x+10,y+10);                      //snake head

                for (k=0;k<score;k++)
                {
                        bar(tailx[k],taily[k],tailx[k]+10,taily[k]+10);
                        if (tailx[k]==x && taily[k]==y)
                            gameover=1;
                }
delay(100);
body();
move();
points();
    if (x==10|| x==width-10 ||y==10||y==height-10)
        gameover=1;
    if (gameover==1)
    {
            break;
    }
}

closegraph();
return 0;
}


void initialise()
{
    score=0;
    gameover=0;
    dir=0;
    x=width/2;
    y=height/2;

label1:
    fruitx=rand()%630;
    fruity=rand()%470;

    if (fruitx<=10 || fruity<=10)
        goto label1;

    fruitx=fruitx/10;
    fruitx=fruitx*10;
    fruity=fruity/10;
    fruity=fruity*10;
}


void move()
{
char a;



    if (GetAsyncKeyState(VK_UP))
    {
        dir=1;
    }
    else if (GetAsyncKeyState(VK_DOWN))
    {
        dir=2;
    }
    else if (GetAsyncKeyState(VK_LEFT))
    {
        dir=3;
    }
    else if (GetAsyncKeyState(VK_RIGHT))
    {
        dir=4;
    }




    switch (dir)
    {
    case 1:
        y=y-10;
        break;
    case 2:
        y=y+10;
        break;
    case 3:
        x=x-10;
        break;
    case 4:
        x=x+10;
        break;
    }
}


void points()
{
    if (x==fruitx && y==fruity)
    {
        score++;

        label2:
    fruitx=rand()%630;
    fruity=rand()%470;

    if (fruitx<=10 || fruity<=10)
        goto label2;
    }

    fruitx=fruitx/10;
    fruitx=fruitx*10;
    fruity=fruity/10;
    fruity=fruity*10;
}


void body()
{
int i;

    for (i=score-1;i>0;i--)
    {
        tailx[i]=tailx[i-1];
        taily[i]=taily[i-1];
    }
    tailx[0]=x;
    taily[0]=y;
}


