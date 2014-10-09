//̰����˫��PK�棬���������� 2012.11.17
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#define SPEED 500

#define LEN sizeof(struct snakeNode)
struct snakeNode //����ѭ����
{
	int x, y;
	struct snakeNode * next;
};
typedef struct snakeHead //��ͷ��ָ����β
{
	int player, direction;
	int x, y;
	struct snakeNode * tail;
}snake;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = 2 * x, c.Y = y; //����Ϸֻʹ��˫�ֽڷ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void welcome(void)
{
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩ�  ������  ������  ������  ������  ������  ������  ������  ������  ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�              ������                                                ���Щ�");
	printf("�ةЩ�            ���ةЩ�                                                ���ة�");
	printf("�Щة�            ������  Welcome to the Snake game!  ������              ���Щ�");
	printf("�ةЩ�          /^\\/^\\                              ���ةЩة�            ���ة�");
	printf("�Щة�        _|__|  O|                             �����ة���          ���ةЩ�");
	printf("�ةЩ� \\/   /~     \\_/ \\                                                ���Щة�");
	printf("�Щة�  \\__|__________/ \\                     \\                           ���Щ�");
	printf("�ةЩ�      \\________    \\                     \\\\                         ���ة�");
	printf("�Щة�               `\\   \\                     \\ \\                     ���ةЩ�");
	printf("�ةЩ�                |   |          ___         \\  \\                   ���Щة�");
	printf("�Щة�               /   /        _-~   ~-_     _/   |                    ���Щ�");
	printf("�ةЩ�              (   (      _-~    __   ~-_-~    /                     ���ة�");
	printf("�Щة�               \\   ~-__-~    _-~  ~-_      _-~          ���������Z  ���Щ�");
	printf("�ةЩ�                ~-_       _-~        ~-__-~             ��      �U  ���ة�");
	printf("�Щة�                   ~-___-~                              ��      �U  ���Щ�");
	printf("�ةЩ�             �������������������Z                 ��������      �U  ���ة�");
	printf("�Щة� [�鿴˵��]����      �ո�      �U   [��ʼ��Ϸ]�밴��Enter �������U  ���Щ�");
	printf("�ةЩ�             �\�T�T�T�T�T�T�T�T�a                 �\�T�T�T�T�T�T�a  ���ة�");
	printf("�Щة�  ������  ������  ������  ������  ������  ������  ������  ������  ���ةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	system("title ̰���� - ˫�˰�");
	gotoxy(0, 0);
}

void explain(void)
{
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩ�  ������  ������  ������  ������  ������  ������  ������  ������  ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�              ������                                                ���Щ�");
	printf("�ةЩ�            ���ةЩ�                                                ���ة�");
	printf("�Щة�            ������       ��̰���ߵ�˵����       ������              ���Щ�");
	printf("�ةЩ�������˵����                                  ���ةЩة�            ���ة�");
	printf("�Щة�                                              �����ة���          ���ةЩ�");
	printf("�ةЩ�    ���1����ĸ��W, S, A, D �ֱ�����ϡ��¡����ҡ�              ���Щة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�    ���2��������� �� �� �������������ҡ�    [F1�� ��ͣ]           ���ة�");
	printf("�Щة�                                                                  ���ةЩ�");
	printf("�ةЩ���ʤ��������                                                      ���Щة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�    ��һ����ҵ���ͷײ��ǽ�����������������һ�����ʤ����          ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�ps:�����ҵ�һ����C����������С��Ϸ���������ţ��´�Ҫ����һ��������Ŷ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�      ���1������      ���2������       ʳ���               ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�  ������  ������  ������  ������  ������  ������  ������  ������  ���ةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	gotoxy(0, 0);
}

void gameover(int player)
{	
	system("color 07");
	gotoxy(0, 0);
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩ�  ������  ������  ������  ������  ������  ������  ������  ������  ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�              ������                                                ���Щ�");
	printf("�ةЩ�            ���ةЩ�                                                ���ة�");
	printf("�Щة�            ������         ����Ϸ������         ������              ���Щ�");
	printf("�ةЩ�                                              ���ةЩة�            ���ة�");
	printf("�Щة�                                              �����ة���            ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�             �������Z                                               ���ة�");
	printf("�Щة�           ����ESC �U �˳���Ϸ���������������Ϸ...                 ���Щ�");
	printf("�ةЩ�             �\�T�T�a                                               ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�                                   ��л���汾��Ϸ^_^ CJ������       ���ة�");
	printf("�Щة�                                                                    ���Щ�");
	printf("�ةЩ�                                                                    ���ة�");
	printf("�Щة�  ������  ������  ������  ������  ������  ������  ������  ������  ���ةЩ�");
	printf("�ةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩة�");
	printf("�ЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩةЩ�");
	gotoxy(11, 11);
		 if(player == 3) printf("��ƽ��Ŷ���ѡ����  ������");
	else if(player == 1) printf("��ʤ�����ǣ����2 ��������");
	else if(player == 2) printf("��ʤ�����ǣ����1 �ѡ������");
	gotoxy(11, 13);
}

void initialize(snake * p1, snake * p2, int g[][25])
{
	int i, j;
	gotoxy(0, 0);			//��ʼ������
	printf("�Щة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة��ة���");
	for(i=0; i<23; i++)
		if(i % 2) printf("��%76c��", ' ');
		else printf("��%76c��", ' ');
	printf("�Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ��Щ�");

	for(i=0; i<40; i++)		//��ʼ������
	{
		for(j=0; j<25; j++)
			if(i==0 || i==39 || j==0 || j==24)
				g[i][j] = 4;
			else
				g[i][j] = 0;
	}

	struct snakeNode * p;
	p1->x = 13, p1->y = 12, g[13][12] = 1;		//��1
	gotoxy(p1->x, p1->y), printf("��");
	p = (struct snakeNode *)malloc(LEN);
	p->x = 13, p->y = 13, g[13][13] = 1;
	gotoxy(p->x, p->y),  printf("��");
	p1->tail = p, p->next = p;

	p2->x = 26, p2->y = 12, g[26][12] = 2;		//��2
	gotoxy(p2->x, p2->y), printf("��");
	p = (struct snakeNode *)malloc(LEN);
	p->x = 26, p->y = 13, g[26][13] = 2;
	gotoxy(p->x, p->y),  printf("��");
	p2->tail = p, p->next = p;

	gotoxy(19, 12), printf("׼��..."), gotoxy(0, 0), Sleep(500);
	gotoxy(19, 12), printf("       "), gotoxy(0, 0), Sleep(100);
	gotoxy(19, 12), printf("��..."), gotoxy(0, 0), Sleep(500);
	gotoxy(19, 12), printf("     "), gotoxy(0, 0), Sleep(100);
	gotoxy(19, 12), printf("��..."), gotoxy(0, 0), Sleep(500);
	gotoxy(19, 12), printf("     "), gotoxy(0, 0), Sleep(100);
	gotoxy(19, 12), printf("һ..."), gotoxy(0, 0), Sleep(500);
	gotoxy(19, 12), printf("     "), gotoxy(0, 0), Sleep(100);
	gotoxy(19, 12), printf("��ʼ��"), gotoxy(0, 0), Sleep(500);
	gotoxy(19, 12), printf("      "), gotoxy(0, 0), Sleep(100);

	while(kbhit()) getch(); //�����ʼ��Ϸǰ����������
	srand(time(NULL)); //�����������
}

void keyboard(char k, int * d1, int * d2, int * s)
{
	if(k == 0) //��ͣ��Ϸ
	{
		while(getch() != 0);
		getch();
	}
	if(*s != 1)
	{
			 if(k == 'w' && *d1 != 3) *d1 = 1, *s += 1;
		else if(k == 'd' && *d1 != 4) *d1 = 2, *s += 1;
		else if(k == 's' && *d1 != 1) *d1 = 3, *s += 1;
		else if(k == 'a' && *d1 != 2) *d1 = 4, *s += 1;
	}
	if(*s != 2)
	{
			 if(k == 72 && *d2 != 3) *d2 = 1, *s += 2;
		else if(k == 77 && *d2 != 4) *d2 = 2, *s += 2;
		else if(k == 80 && *d2 != 1) *d2 = 3, *s += 2;
		else if(k == 75 && *d2 != 2) *d2 = 4, *s += 2;
	}
}

void createfood(int g[][25])
{
	int x, y;
	do
	{
		x = rand() % 38 + 1;
		y = rand() % 23 + 1;
	}while(g[x][y]);
	g[x][y] = 3;
	gotoxy(x, y), printf("��");
}

int move(snake * head, int g[][25])
{
	struct snakeNode * p;
	int x = head->x, y = head->y;
	int food = 0;

		 if(head->direction==1) (head->y)--; //��ͷ�ƶ�
	else if(head->direction==2) (head->x)++;
	else if(head->direction==3) (head->y)++;
	else if(head->direction==4) (head->x)--;

	if(g[head->x][head->y] == 3) //���˶���
	{
		p = (struct snakeNode *)malloc(LEN);
		p->x = x, p->y = y;
		p->next = head->tail->next;
		head->tail->next = p;
		food = 1;
	}
	else if(g[head->x][head->y]) //��Ϸ����
	{
		system("color 40");
		p = head->tail;
		while(p->next != head->tail)
		{
			gotoxy(p->x, p->y), printf("��");
			p = p->next;
			Sleep(100);
		}
		gotoxy(p->x, p->y), printf("��");
		Sleep(2000);
		while(kbhit()) getch(); //���������������ǰ����������
		return 4;
	}
	else //�����ƶ�
	{
		p = head->tail;
		gotoxy(p->x, p->y), printf("  ");
		g[p->x][p->y] = 0;
		p->x = x, p->y = y;
		do
		{
			p = p->next;
		}while(head->tail != p->next);
		head->tail = p;
	}

	gotoxy(head->x, head->y);
	if(head->player==1) printf("��");
	else printf("��");
	gotoxy(x, y);
	if(head->player==1) printf("��");
	else printf("��");

	g[head->x][head->y] = head->player;
	return food;
}


int main() //��ѡ���
{
	int gridding[40][25]; //ֵ0��ʾ�յأ�ֵ1��ʾ��1��ֵ2��ʾ��2��ֵ3��ʾʳ�ֵ4��ʾ�ϰ���
	int snake1, snake2;   //ֵ0��ʾ������ֵ1��ʾ���˶�����ֵ4��ʾ����
	int keySwitch, grade, speed, win1 = 0, win2 = 0;
	char key = 0;
	clock_t millisecond;
	snake p1, p2;
	
	welcome(); //��ʼ���棬Enter������Ϸ���ո������˵������
	while(key != 13 && key != 32) key = getch();
	if(key == 32) explain(), getch();

	do
	{
		p1.player = 1, p1.direction = 1; //��ʼ������
		p2.player = 2, p2.direction = 1;
		keySwitch = 0, grade = 0, speed = 150, snake1 = 0, snake2 = 0;
		initialize(&p1, &p2, gridding);
		createfood(gridding), grade++;
		millisecond = clock();

		while(snake1 != 4 && snake2 != 4)
		{
			if( kbhit() )
			{
				key = getch();
				if(key == 224) key = getch();
				if(keySwitch < 3) //�������ƶ�һ��ǰ�����������ֲ�ͬ����ָ��Ĳ���
				{
					keyboard(key, &(p1.direction), &(p2.direction), &keySwitch);
				}
			}
			else if(clock() - millisecond > speed)
			{
				snake1 = move(&p1, gridding);
				snake2 = move(&p2, gridding);
				if(snake1 == 4 || snake2 == 4) break; 
				else if(snake1 ==1 || snake2 ==1) createfood(gridding), grade++;
				snake1 = 0, snake2 = 0, keySwitch = 0;
				if(grade == 10)
				{
					grade++;
					speed = 60;
					system("color 0F"), Sleep(500);
					system("color 07"), Sleep(300);
					system("color 0F"), Sleep(300);
				}
				else if(grade == 15)
				{
					grade++;
					speed = 80;
					system("color 0E");
				}
				else if(grade == 30)
				{
					grade++;
					speed = 100;
					system("color 0B");
				}
				else if(grade == 40)
				{
					grade++;
					speed = 120;
					system("color 0D");
				}
				else if(grade == 60)
				{
					grade++;
					speed = 90;
					system("color 0C"), Sleep(500);
					system("color 0D"), Sleep(300);
					system("color 0C"), Sleep(300);
				}
				millisecond = clock();
			}
		}

		struct snakeNode * pp1, * pp2; //��Ϸ�����������������
		pp1 = p1.tail->next;
		while(p1.tail != pp1)
		{
			pp2 = pp1->next;
			free(pp1);
			pp1 = pp2;
		}
		free(p1.tail);
		pp1 = p2.tail->next;
		while(p2.tail != pp1)
		{
			pp2 = pp1->next;
			free(pp1);
			pp1 = pp2;
		}
		free(p2.tail);

		if(snake1 == 4 && snake2 == 4) gameover(3); //��������
		else if(snake1 == 4) gameover(1), win2++;
		else if(snake2 == 4) gameover(2), win1++;
		printf("[���1ʤ��%d��] VS [���2ʤ��%d��]", win1, win2);
		gotoxy(0, 0);

		if(getch()==27) exit(0); //ѡ���������˳�
	}while(1);
}

//���漰���ĺ���˵��
/* 
<conio.h>
int getch(void)
	�ӿ���̨��ȡһ���ַ���������ʾ����Ļ�ϣ����ض�ȡ���ַ���
int kbhit(void)
	��鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0��

<time.h>
time_t time(time_t *timer)
	�õ�����������ʱ�������������ʱ�䡣
	timer=NULLʱ�õ���������ʱ�䣬timer=ʱ����ֵʱ��������������ʱ�䣬time_t��һ��long���͡�
clock_t clock(void)
�����õ��ӳ����������˴κ�������ʱ�ۼƵĺ�������

<windows.h>
Sleep(unsigned long)
	������ͣ����ʱ�䣬��λ�Ǻ��롣ע���һ����ĸ�Ǵ�д��

<stdlib.h>
void srand(unsigned int)
	�����ӣ�ʹ����ͬ�����Ӻ����rand()���������һ������������������srand(time(NULL));
int rand()
	����0~RAND_MAX֮���һ�����������ָ����˳������������
*/

/*
//�����������λ�õķ���
#include<windows.h>

void gotoxy(int x, int y) {
COORD c;
c.X = x - 1;
c.Y = y - 1;
SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{ 
return 0;
}
���е�COORD��SetConsoleCursorPosition������wincon.h��
SetConsoleCursorPosition��������Ӧ���豸���ù���λ�ã����������ֱ����豸����͹��λ�ýṹ
GetStdHandle������winbase.h�����ڻ�ñ�׼���롢���������������
��������ʶΪSTD_OUTPUT_HANDLEʱ��ñ�׼������
*/