#include<stdio.h>
#include<unistd.h>
#include<curses.h>
#include<string.h>
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
		flag = snake_dir;
		break;
		case 'a':
		snake_dir = DIR_LEFT;
		flag = snake_dir;
		break;
		case 'w':
		snake_dir = DIR_ON;
		flag = snake_dir;
		break;
		case 's':
		snake_dir = DIR_UNDER;
		flag = snake_dir;
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

int s_foodju(int h , int *c,int *time_s)
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
				return 0;
				break;
				case'&':
				(*c)+=2;
				return 0;
				break;
				case'%':
				(*c)+=3;
				return 0;
				break;
				}
			if(strcmp(food_save[i].food,">>")==0)
				{
				move(food_save[i].y,food_save[i].x+1);
				addstr(" ");
				(*time_s) = (*time_s)/2;
				return 1;				
				//set_ticker((*time));
				}
			if(strcmp(food_save[i].food,"<<")==0)
				{
				move(food_save[i].y,food_save[i].x+1);
				addstr(" ");
				(*time_s) =(*time_s) * 2;
				return 1;				
				//set_ticker(time);
				}
			break;
		}
	}
	}
	return  0;
}

int s_hit_wall_or_body(int h, int b)
{
	int hit=0,i = 0;
	if(b_d[(h-1)%20].y==0||b_d[(h-1)%20].y==MAP_MAX)
	{
		hit = 1;

	}
	else
	if(b_d[(h-1)%20].x==0||b_d[(h-1)%20].x==2*MAP_MAX)
	{
		hit = 1;
	}
	else
	for(i = 1 ; i<=b;i++){
		if(b_d[(h-i-1)%20].x==b_d[(h-1)%20].x&&b_d[(h-i-1)%20].y==b_d[(h-1)%20].y)
		hit = 1;
	}
	return hit;

}
