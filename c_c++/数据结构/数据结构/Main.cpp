/****************************************************
 
 ***** ���ƣ�    ���ݽṹ�ϼ�ϰ��
 ***** ���ߣ�    CJ������ 
 ***** ����ʱ�䣺2012��11��9��

*****************************************************/

#include "hMybase.h"

void interwin();
void clockend(clock_t begin);
int mainmenu();
int menuA();
int menuB();
int menuC();
int menuD();
int menuE();
clock_t begin;

int main()
{
	interwin();
	begin=clock();

	mainmenu();		//�˵��������

	clockend(begin);	//��������
	return 0;
}

//���˵�����
int mainmenu()
{
	
	int i;
	char input='y';
	char me1='1';
	char me2='a';
	system("cls");
	system("color 1f");
	P("\t\t***************************************\n");
	P("\t\t*******      ���ݽṹʵ��       *******\n");
	P("\t\t***************************************\n\n");
	P("\t\t%c.������ʵ��\n",me1);me1++;
	 P("\t\t\t%c.\n",me2);me2++;
	P("\t\t%c.ջ��ʵ��\n",me1);me1++;
	 
	P("\t\t%c.��ʵ��\n",me1);me1++;
	 
	P("\t\t%c.������ʵ��\n",me1);me1++;
	printf("\n\t\t\t\t���� �밴 Cirl+S ��������\n");
	printf("\t\t\t\t�˳� �밴 ESC ��������\n");
	 

	system("pause");
	return 0;
}

//������
int menuA()
{
	return 0;
}

//ջ
int menuB()
{
	return 0;
}

//��
int menuC()
{
	return 0;
}

//������
int menuD()
{
	return 0;
}

//
int menuE()
{
	return 0;
}

//��������ʱ���˳����溯��
void clockend(clock_t begin)
{
	int i;
	system("cls");
	system("color 02");
	clock_t end;
	time_t cost,ntime;
	struct tm *ctm ,*ntm;
	ntime=time(NULL);
	ntm=localtime(&ntime);
	printf("\n�����ǣ�%4d��%2d��%2d��  %dʱ%d��%02d��\n",ntm->tm_year+1900,ntm->tm_mon+1,ntm->tm_mday,ntm->tm_hour, ntm->tm_min,ntm->tm_sec);
	end=clock();
	cost=(int)(end-begin)/ 1000;
	ctm=localtime(&cost);
	Sleep(200);
	printf("\n������ʱ��%d��%02d��\n", ctm->tm_min,ctm->tm_sec);
	Sleep(200);
	printf("\nллʹ��");
	for(int i=1;i<6;i++)
	{
		Sleep(250);
		printf("\a!");
	}
	printf("\n");
	Sleep(800);
	exit(0);
}

//��������뺯��
void interwin()
{
	int i;
	system("color 02");
	P("\n\n\n\n\n");
	P("\a\t\t***************************************\n");
	P("\t\t***                                 ***\n");
	P("\t\t***   ���ݽṹ V1.0                 ***\n");
	P("\t\t***                                 ***\n");
	P("\t\t***   CJ������                      ***\n");
	P("\t\t***                                 ***\n");
	P("\t\t***   2012��11��11��                ***\n");
	P("\t\t***                                 ***\n");
	P("\t\t***************************************\n\n\n\n\n\a");
	for(i=1;i<40;i++)
	{
		printf("--");
	};
	Sleep(500);
	printf("\r");
	for(i=1;i<40;i++)
	{
		Sleep(40);
		printf(" >");
	};
	printf("\n\n\n");
	system("pause");
}