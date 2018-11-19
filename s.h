#define MAP_MAX 30
typedef struct food_add{
	int x;
	int y;
	int vaild;
	char *food;

}fa;
typedef struct body_add{
	int x;
	int y;

}bd;
fa food_save[7];
bd b_d[20];
//int head = 4;
//int body = 3;
void s_f_p();
void s_food();
void body_i();
void body_p();
void s_dir(char );
