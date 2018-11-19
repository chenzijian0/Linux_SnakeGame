#include<stdio.h>
#include"s.h"
#include<curses.h>
int head = 6;
int body = 5;
void body_i(){
	int i = 0;
	b_d[head-1].x = MAP_MAX / 2 + 1;
	b_d[head-1].y = MAP_MAX / 2 + 1;
	for(i = 1 ; i<=body ; i++)
 	{
	b_d[head - 1 - i].x = MAP_MAX / 2 + 1;
	b_d[head - 1 - i].y = MAP_MAX / 2 + 1 -i;
	}

}

void  body_p()
{
	int i = 0;
	move(b_d[head - 1].y,b_d[head - 1].x);
		addstr("9");
	for(i = 1 ; i <= body ; i++)
	{
		move(b_d[head - 1 - i].y,b_d[head - 1 - i].x);
		addstr("9");
	}
}














