#include<stdio.h>
#include"s.h"
#include<curses.h>
//int head = 6;
//int body = 5;
void body_i(int h,int b){
	int i = 0;
	b_d[h-1].x = MAP_MAX / 2 + 1;
	b_d[h-1].y = MAP_MAX / 2 + 1;
	for(i = 1 ; i<=b ; i++)
 	{
	b_d[h - 1 - i].x = MAP_MAX / 2 + 1;
	b_d[h - 1 - i].y = MAP_MAX / 2 + 1 -i;
	}

}

void  body_p(int h,int b)
{
	int i = 0;
	//head %= 20; 
	move(b_d[h - 1].y,b_d[h - 1].x);
		addstr("1");
	for(i = 1 ; i <= b ; i++)
	{
		move(b_d[h - 1 - i].y,b_d[h - 1 - i].x);
		addstr("9");
	}
	move(LINES-1,0);
}














