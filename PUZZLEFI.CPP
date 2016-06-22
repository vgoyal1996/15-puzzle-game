#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int getkey();
void rightkey();
void leftkey();
void upkey();
void downkey();
int r,j,a,b,number[4][4],y;
int ans[4][4];
int check();
char arr[50];
void main()
{
	clrscr();
	int gd=DETECT,gm;
	int x,temp,k,count=0,l,i=0,f,num[16],val,row1,col,inc=1;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	setbkcolor(YELLOW);
	setcolor(RED);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
	outtextxy(150,50,"15 SLIDE PUZZLE");
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	outtextxy(200,400,"press any key to see the instructions");
	getch();
	cleardevice();
	graphdefaults();
	setbkcolor(CYAN);
	setcolor(RED);
	settextstyle(COMPLEX_FONT,HORIZ_DIR,4);
	outtextxy(150,50,"15 SLIDE PUZZLE");
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
	outtextxy(0,300,"use the arrow keys to move the black box (white box)");
	outtextxy(0,325,"and arrange the numbers in ascending order from top");
	outtextxy(0,350,"to bottom.");
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,4);
	outtextxy(100,400,"ARE YOU READY????");
	outtextxy(100,500,"press any key to start the game");
	getch();
	cleardevice();
	graphdefaults();
	line(100,50,500,50);
	line(100,150,500,150);
	line(100,250,500,250);
	line(100,350,500,350);
	line(100,450,500,450);
	line(100,50,100,450);
	line(500,50,500,450);
	line(200,50,200,450);
	line(300,50,300,450);
	line(400,50,400,450);
	randomize();
	for(r=150,a=0;r<=450&&a<=3;r+=100,a++)
	{
		for(j=100,b=0;j<=400&&b<=3;j+=100,b++)
		{
			if(r==450&&j==400)
			{
				gotoxy(r,j);
				printf("%c",32);
				number[b][a]=32;
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(r,j,WHITE);
			}
			else
			{
				there:
				temp=random(15)+1;
				int f=1;
				if(i!=0)
				{
					for(l=0;l<i;l++)
					{
						if(num[l]==temp)
						{
							f=0;
							break;
						}
					}
					if(f==0)
						goto there;
					else
					{
						num[i]=temp;
						i++;
						number[b][a]=temp;
						sprintf(arr,"%d",temp);
						outtextxy(r,j,arr);
					}
				}
				else
				{
					num[i]=temp;
					i++;
					number[b][a]=temp;
					sprintf(arr,"%d",temp);
					outtextxy(r,j,arr);
				}
			}
		}
	}
	a=3;
	b=3;
	r=450;
	j=400;
	for(row1=0;row1<=3;row1++)
	{
		for(col=0;col<=3;col++)
		{
			if(row1==3&&col==3)
				ans[row1][col]=32;
			else
			{
				ans[row1][col]=inc;
				inc++;
			}
		}
	}
	while(val!=1)
	{
		k=getkey();
		if(k==75)
		{
			if(r>150)
			{
				leftkey();
				count++;
				val=check();
			}
		}
		else if(k==77)
		{
			if(r<450)
			{
				rightkey();
				count++;
				val=check();
			}
		}
		else if(k==72)
		{
			if(j>100)
			{
				upkey();
				count++;
				val=check();
			}
		}
		else if(k==80)
		{
			if(j<400)
			{
				downkey();
				count++;
				val=check();
			}
		}
	}
	if(val==1)
	{
		outtextxy(500,40,"CONGRATULATIONS!!");
		gotoxy(500,80);
		printf("you won the game in %d steps",count);
		outtextxy(500,120,"press any key to ");
		outtextxy(500,145,"exit");
	}
	getch();
	closegraph();
}
int getkey()
{
	int ch;
	ch=getch();
	if(ch==0)
	{
		ch=getch();
		return ch;
	}
	return ch;
}
void leftkey()
{
	int x1,y1,z1,w1;
	cleardevice();
	graphdefaults();
	line(100,50,500,50);
	line(100,150,500,150);
	line(100,250,500,250);
	line(100,350,500,350);
	line(100,450,500,450);
	line(100,50,100,450);
	line(500,50,500,450);
	line(200,50,200,450);
	line(300,50,300,450);
	line(400,50,400,450);
	x1=b;
	y1=r;
	z1=a;
	w1=j;
	y=number[a][b];
	number[a][b]=number[a][b-1];
	number[a][b-1]=y;
	for(r=150,a=0;r<=450&&a<=3;r+=100,a++)
	{
		for(j=100,b=0;j<=400&&b<=3;j+=100,b++)
		{
			if(number[b][a]==32)
			{
				gotoxy(r,j);
				printf("%c",32);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(r,j,WHITE);
			}
			else
			{
				sprintf(arr,"%d",number[b][a]);
				outtextxy(r,j,arr);
			}
			if(j==400&&b==3)
				break;
		}
		if(r==450&&a==3)
			break;
	}
	x1=x1-1;
	y1=y1-100;
	b=x1;
	r=y1;
	a=z1;
	j=w1;
}
void rightkey()
{
	int x2,y2,z2,w2;
	cleardevice();
	graphdefaults();
	line(100,50,500,50);
	line(100,150,500,150);
	line(100,250,500,250);
	line(100,350,500,350);
	line(100,450,500,450);
	line(100,50,100,450);
	line(500,50,500,450);
	line(200,50,200,450);
	line(300,50,300,450);
	line(400,50,400,450);
	x2=b;
	y2=r;
	z2=a;
	w2=j;
	y=number[a][b];
	number[a][b]=number[a][b+1];
	number[a][b+1]=y;
	for(r=150,a=0;r<=450&&a<=3;r+=100,a++)
	{
		for(j=100,b=0;j<=400&&b<=3;j+=100,b++)
		{
			if(number[b][a]==32)
			{
				gotoxy(r,j);
				printf("%c",32);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(r,j,WHITE);
			}
			else
			{
				sprintf(arr,"%d",number[b][a]);
				outtextxy(r,j,arr);
			}
			if(j==400&&b==3)
				break;
		}
		if(r==450&&a==3)
			break;
	}
	x2=x2+1;
	y2=y2+100;
	b=x2;
	r=y2;
	a=z2;
	j=w2;
}
void upkey()
{
	int x3,y3,z3,w3;
	cleardevice();
	graphdefaults();
	line(100,50,500,50);
	line(100,150,500,150);
	line(100,250,500,250);
	line(100,350,500,350);
	line(100,450,500,450);
	line(100,50,100,450);
	line(500,50,500,450);
	line(200,50,200,450);
	line(300,50,300,450);
	line(400,50,400,450);
	x3=a;
	y3=j;
	z3=b;
	w3=r;
	y=number[a][b];
	number[a][b]=number[a-1][b];
	number[a-1][b]=y;
	for(r=150,a=0;r<=450&&a<=3;r+=100,a++)
	{
		for(j=100,b=0;j<=400&&b<=3;j+=100,b++)
		{
			if(number[b][a]==32)
			{
				gotoxy(r,j);
				printf("%c",32);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(r,j,WHITE);
			}
			else
			{
				sprintf(arr,"%d",number[b][a]);
				outtextxy(r,j,arr);
			}
			if(j==400&&b==3)
				break;
		}
		if(r==450&&a==3)
			break;
	}
	x3=x3-1;
	y3=y3-100;
	a=x3;
	j=y3;
	b=z3;
	r=w3;
}
void downkey()
{
	int x4,y4,z4,w4;
	cleardevice();
	graphdefaults();
	line(100,50,500,50);
	line(100,150,500,150);
	line(100,250,500,250);
	line(100,350,500,350);
	line(100,450,500,450);
	line(100,50,100,450);
	line(500,50,500,450);
	line(200,50,200,450);
	line(300,50,300,450);
	line(400,50,400,450);
	x4=a;
	y4=j;
	z4=b;
	w4=r;
	y=number[a][b];
	number[a][b]=number[a+1][b];
	number[a+1][b]=y;
	for(r=150,a=0;r<=450&&a<=3;r+=100,a++)
	{
		for(j=100,b=0;j<=400&&b<=3;j+=100,b++)
		{
			if(number[b][a]==32)
			{
				gotoxy(r,j);
				printf("%c",32);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(r,j,WHITE);
			}
			else
			{
				sprintf(arr,"%d",number[b][a]);
				outtextxy(r,j,arr);
			}
			if(j==400&&b==3)
				break;
		}
		if(r==450&&a==3)
			break;
	}
	x4=x4+1;
	y4=y4+100;
	a=x4;
	j=y4;
	b=z4;
	r=w4;
}
int check()
{
	int row,column,flag1=1;
	for(row=0;row<=3;row++)
	{
		for(column=0;column<=3;column++)
		{
			if(ans[row][column]!=number[row][column])
			{
				flag1=0;
				break;
			}
		}
	}
	if(flag1==0)
		return 0;
	else
		return 1;
}








