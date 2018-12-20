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
	move(b_d[(h - 1)%20].y,b_d[(h - 1)%20].x);
		addstr("@");
	for(i = 1 ; i <= b ; i++)
	{
		move(b_d[(h - 1 - i)%20].y,b_d[(h - 1 - i)%20].x);
		addstr("#");
	}
	move(LINES-1,0);
}


void body_c(int c ,int *b)
{	
	c = c /5 ;
	(*b)=5+c;
	
}











