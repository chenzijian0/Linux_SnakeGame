#include<sys/time.h>
#include<signal.h>
#include<pthread.h>
#include<stdio.h>
#include<curses.h>
#include<unistd.h>
#include"s.h"
// s_food();
// s_f_p();
void print_map();
void re();
void main()
{
	
	int time_s = 250;
	signal(SIGALRM,re);
	set_ticker(time_s);
	char *p_t;
	char *p_s;
	p_t  = malloc(sizeof(char )* 20);
	p_s  = malloc(sizeof(char )* 20);
	int hit = 0;
	score_count = 0;
	head = 6;
	body = 5;
	int i =0;
	initscr();
	body_i(head,body);
	body_p(head,body);
	pthread_t t1,t2;
	pthread_create(&t2,NULL,s_food,(void*)1);
	
	pthread_create(&t1,NULL,s_getch,(void*)" ");
	print_map();
	while(1){
	//clear();

	//s_food();
	s_f_p();

	head++;
	s_dir();
	s_nextdir(head,body);
	hit = s_hit_wall_or_body(head,body);
	
	if(s_foodju(head,&score_count,&time_s))
	{
	set_ticker(time_s);
	}
	body_c(score_count,&body);
	//body_p(head,body);
	move(b_d[(head - 1)%20].y,b_d[(head - 1)%20].x);
	addstr("1");
	move(b_d[(head - 1 - 1)%20].y,b_d[(head - 1 - 1)%20].x);
	addstr("9");
	move(b_d[(head - 1 - body -1)%20].y,b_d[(head - 1 - body -1)%20].x);
	addstr(" ");
	sprintf(p_s,"Score count : %d",score_count);
	move(0,2*MAP_MAX+5);
	addstr(p_s);
	refresh();
	if(score_count>65)
	{
		move(3,2*MAP_MAX+5);
		addstr("YOU ARE LONG ENOUGH");
		refresh();
		set_ticker(10000);
		sleep(10);
		endwin();
		exit(0);

	}
	if(hit)
	{
		move(3,2*MAP_MAX+5);
		addstr("GAME OVER");
		refresh();
		set_ticker(10000);
		sleep(10);
		endwin();
		exit(0);
	}
	pause();
	
	//pause();
	//sleep(1);	
	//getch();
	}
	endwin();
}
void print_map()
{
	int i = 0;
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
}
void re()
{
	return;
}
