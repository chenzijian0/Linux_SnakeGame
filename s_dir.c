#include<stdio.h>
#include"s.h"
#define DIR_LEFT 1
#define DIR_RIGHT -1
#define DIR_ON -2
#define DIR_UNDER 2
int flag = -1;
int snake_dir = -1;
char dir;
void s_getch()
{
	dir = 'l';	
	while(1){
	dir = getchar();
	}
}
void s_dir()
{
	
	switch(dir)
	{
	case 100:
	flag += DIR_RIGHT;
	break;
	case 97:
	flag += DIR_LEFT;
	break;
	case 119:
	flag += DIR_ON;
	break;
	case 115:
	flag += DIR_UNDER;
	break;
	}
	if(flag)
	{
		switch(dir)
		{
		case 100:
		flag = DIR_RIGHT;
		break;
		case 97:
		flag = DIR_LEFT;
		break;
		case 119:
		flag = DIR_ON;
		break;
		case 115:
		flag = DIR_UNDER;
		break;
		}
	}
	else
	flag = snake_dir;

}

void s_nextdir(int h,int b)
{
	
	
	switch(flag)
	{
	case 1:
	b_d[h-1].x =b_d[h-2].x-1;
	b_d[h-1].y =b_d[h-2].y;
	break;
	case -1:
	b_d[h-1].x =b_d[h-2].x+1;
	b_d[h-1].y =b_d[h-2].y;
	break;
	case 2:
	b_d[h-1].x =b_d[h-2].x;
	b_d[h-1].y =b_d[h-2].y+1;
	break;
	case -2:
	b_d[h-1].x =b_d[h-2].x;
	b_d[h-1].y =b_d[h-2].y-1;
	break;
	
	}
	
}
