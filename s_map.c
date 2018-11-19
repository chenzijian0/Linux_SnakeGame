#include<pthread.h>
#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"s.h"
// s_food();
// s_f_p();
void main()
{
	head = 6;
	body = 5;
	int i =0;
	initscr();
	body_i(head,body);
	pthread_t t1;
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
	pthread_create(&t1,NULL,s_dir,(void*)" ");
	s_food();
	s_f_p();
	body_p(head,body);	
	head++;
	s_nextdir(head,body);
	refresh();
	sleep(1);	
	//getch();
	}
	endwin();
}
