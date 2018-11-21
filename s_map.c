#include<sys/time.h>
#include<signal.h>
#include<pthread.h>
#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"s.h"
// s_food();
// s_f_p();

void re();
void main()
{
	int hit = 0;
	signal(SIGALRM,re);
	set_ticker(500);
	char *p_s;
	score_count = 0;
	head = 6;
	body = 5;
	int i =0;
	initscr();
	body_i(head,body);
	pthread_t t1;
	
	pthread_create(&t1,NULL,s_getch,(void*)" ");
	while(1){
	clear();
	
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
	s_food();
	s_f_p();
	body_p(head,body);	
	sprintf(p_s,"Score count : %d",score_count);
	move(0,2*MAP_MAX+5);
	addstr(p_s);
	refresh();
	pause();
	head++;
	s_dir();
	s_nextdir(head,body);
	hit = s_hit_wall_or_body(head,body);
	if(hit)
	{
		move(3,2*MAP_MAX+5);
		addstr("GAME OVER");
		refresh();
		set_ticker(5000);
		sleep(5);
		endwin();
		exit(0);
	}
	s_foodju(head,&score_count);
	
	//pause();
	//sleep(1);	
	//getch();
	}
	endwin();
}

void re()
{
	return;
}
