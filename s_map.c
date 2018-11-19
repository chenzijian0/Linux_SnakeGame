#include<pthread.h>
#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"s.h"
// s_food();
// s_f_p();
void main()
{
	int head1 = head;
	int i =0;
	initscr();
	body_i();
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
	//pthread_create(&t1,NULL,s_dir,(void*)" ");
	s_food();
	s_f_p();
	body_p();	
	s_nextdir();
	refresh();
	sleep(1);	
	//getch();
	}
	endwin();
}
