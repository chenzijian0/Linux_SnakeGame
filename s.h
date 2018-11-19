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

static int head;
static int body;
void s_f_p();
void s_food();
void body_i(int ,int);
void body_p(int ,int);
void s_dir();
void s_nextdir(int ,int);
