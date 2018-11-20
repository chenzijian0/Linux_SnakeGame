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
	char dir2;
	dir2 = dir;
	switch(dir2)
	{
	case 'd':
	flag += DIR_RIGHT;
	break;
	case 'a':
	flag += DIR_LEFT;
	break;
	case 'w':
	flag += DIR_ON;
	break;
	case 's':
	flag += DIR_UNDER;
	break;
	}
	if(flag!=0)
	{
		switch(dir2)
		{
		case 'd':
		snake_dir = DIR_RIGHT;
		break;
		case 'a':
		snake_dir = DIR_LEFT;
		break;
		case 'w':
		snake_dir = DIR_ON;
		break;
		case 's':
		snake_dir = DIR_UNDER;
		break;
		}
	}
	else
	flag = snake_dir;

}

void s_nextdir(int h,int b)
{
	
	
	switch(snake_dir)
	{
	case 1:
	b_d[(h-1)%20].x =b_d[(h-2)%20].x-1;
	b_d[(h-1)%20].y =b_d[(h-2)%20].y;
	break;
	case -1:
	b_d[(h-1)%20].x =b_d[(h-2)%20].x+1;
	b_d[(h-1)%20].y =b_d[(h-2)%20].y;
	break;
	case 2:
	b_d[(h-1)%20].x =b_d[(h-2)%20].x;
	b_d[(h-1)%20].y =b_d[(h-2)%20].y+1;
	break;
	case -2:
	b_d[(h-1)%20].x =b_d[(h-2)%20].x;
	b_d[(h-1)%20].y =b_d[(h-2)%20].y-1;
	break;
	
	}
	
}

void s_foodju(int h , int *c)
{
	int i = 0;
	for(i = 0; i<7;i++)
	{
	if(food_save[i].x==b_d[(h-1)%20].x&&food_save[i].y==b_d[(h-1)%20].y)
	{
		if(food_save[i].vaild)
		{
			food_save[i].vaild = 0;
			switch(*food_save[i].food)
			{
				case'*':
				(*c)+=1;
				break;
				case'&':
				(*c)+=2;
				break;
				case'%':
				(*c)+=3;
				break;
				case'#':
				(*c)+=4;
				break;
				case'@':
				(*c)+=5;
				break;
			}
		}
	}
	}
}
