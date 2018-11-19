#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"s.h"
// s_food();
// s_f_p();
void main()
{
	int i =0;
	initscr();
	while(1){
	clear();
	move(0,0);
	for(i=0;i<2*MAP_MAX;i++)
	{
	move(0,i);
	addstr("-");
	}

	for(i=0;i<MAP_MAX;i++)
	{
	move(i,0);
	addstr("|");
	
	}
	for(i=0;i<MAP_MAX;i++)
	{
	move(i,MAP_MAX*2);
	addstr("|");
	}
	for(i = 0; i<2*MAP_MAX ;i++)
	{
	move(MAP_MAX,i);
	addstr("-");
	}
	body_i();
	body_p();
	s_food();
	s_f_p();
	sleep(2);
	refresh();	
	//getch();
	}
	endwin();
}
