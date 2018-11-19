#include<stdio.h>
#include"s.h"
#define DIR_LEFT 1
#define DIR_RIGHT -1
#define DIR_ON 2
#define DIR_UNDER -2

void s_dir(char now)
{
	static int flag = 0;
	switch(now)
	{
	case 100:
	flag += DIR_RIGHT;
	break;
	case 97:
	flag += DIR_LEFT;
	break;
	case 119:
	flag += DIR_ON;
	break;
	case 115:
	flag += DIR_UNDER;
	break;
	}
	if(flag)
	{
		switch(now)
		{
		case 100:
		flag = DIR_RIGHT;
		break;
		case 97:
		flag = DIR_LEFT;
		break;
		case 119:
		flag = DIR_ON;
		break;
		case 115:
		flag = DIR_UNDER;
		break;
		}
	}

}
