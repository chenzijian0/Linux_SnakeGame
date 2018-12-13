#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<time.h>
#include<unistd.h>
#include"s.h"

void s_food(void* c)
{	
	int i = 0;
	char *food1 = "*",*food2 = "&",*food3 = "%",*food4 = ">>",*food5 = "<<";
	int x, y ;
	
	int foodchose;
	srand((unsigned)time(NULL));
	while(1){
	foodchose = rand()%15 + 1 ;
	x = rand()%(MAP_MAX-2)+1;
	y = rand()%(MAP_MAX-2)+1;
	switch(foodchose)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:

	i = (int)c % 7;
		food_save[i].x = x;
		food_save[i].y = y;
		food_save[i].food =  food1;
		food_save[i].vaild = 1;
		break;
		
	
	break;
	case 6:
	case 7:
	case 8:
	case 9:

	i = (int)c % 7;
		food_save[i].x = x;
		food_save[i].y = y;
		food_save[i].food =  food2;
		food_save[i].vaild = 1;
		break;
		
	
	break;
	case 10:
	case 11:
	case 12:

	i = (int)c % 7;
		food_save[i].x = x;
		food_save[i].y = y;
		food_save[i].food =  food3;
		food_save[i].vaild = 1;
		break;
		
	
	break;
	case 13:
	case 14:

	i = (int)c % 7;
		food_save[i].x = x;
		food_save[i].y = y;
		food_save[i].food =  food4;
		food_save[i].vaild = 1;
		break;
		
	
	break;
	case 15:

	i = (int)c % 7;
		food_save[i].x = x;
		food_save[i].y = y;
		food_save[i].food =  food5;
		food_save[i].vaild = 1;
		break;
		
	
	break;

	}
	(int )c++;
	sleep(2);
	}
}

void s_f_p()
{
	int i = 0;
	for( i = 0 ; i< 7 ;i++ )
	{
		if(food_save[i].vaild == 1)
		{
		move(food_save[i].y,food_save[i].x);
				
		//addstr(f);
		addstr(food_save[i].food);
		}
	}	
}
