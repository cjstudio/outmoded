#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

#include <fstream>

#include "test.h"
#include "employeemanager.h"

using namespace std;

void gotoxy(int x, int y) //goto语句
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void testCmd()
{
    system("cls");
    for(int i = 1;i<10;i++)
    {
        gotoxy(i,i);
        cout<<"#";
    }

}
void testEmployeemanager()
{
    EmployeeManager e;
    e.xitongjiemian(5);
}
void testWriteFile()
{
    ofstream out("out.txt");
    if (out.is_open())
    {
        out << "This is a line.\n";
        out << "This is another line.\n";
        out.close();
    }
}

void testttt(int n)
{
    int c = 0;
    for(int i = 0 ; i<n-1; i++)
    {
        for(int j =0,k=i+1;j<=i;j++,k++)
        {
            printf("%d\t",(j==0?0:1)*10+(j==0?k:k-1));
        }
        printf("\n");
        c++;
    }
    for(int i =0,j=n;i<n;i++,j++)
    {
        printf("%d\t",j);
    }
    printf("\n");
}

int main()
{
//    cout << "Hello World!" << endl;
//    system("color 02");
    testEmployeemanager();
//    testWriteFile();
//    int c = getch();
//    cout << c <<endl ;
    system("pause");
    return 0;
}

