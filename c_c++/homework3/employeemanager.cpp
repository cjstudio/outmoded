#include "employeemanager.h"

EmployeeManager::EmployeeManager()
{
    file_path = "employee.cjdb";
    e= new LIST_EMP();
}
EmployeeManager::~EmployeeManager()
{
    delete(e);
}

int EmployeeManager::xitongjiemian(int site)
{
    while(site>=0)
    {
        switch (site) {
        case START_IFACE:
            site = this->interWel();
            break;
        case MAIN_IFACE:
            site = this->interMain();
            break;
        case ERROR_IFACE:
            break;
        case OVER_IFACE:
            site = this->interBye();
            break;
        case UPDATE_IFACE:
            site = this->interUpdate();
            break;
        case SELECT_IFACE:
            site = this->interSelect();
            break;
        case DELETE_IFACE:
            site = this->interDelete();
            break;
        case ADD_IFACE:
            site = this->interAdd();
            break;
        case COMPUTE_WAGE_IFACE:
            site = this->interComputeWage();
            break;
        case COMPUTE_SALARY_IFACE:
            site = this->interComputeSalary();
            break;
        default:
            break;
        }
    };
    return 0;
}

int EmployeeManager::interWel()
{
    system("cls");
    system("color 1f");
    gotoXY(1,5);
    cout<< "\t\t+*****************************************+"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t*               C++_Homework              *"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t+*****************************************+"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t*          Author:    CJStudio            *"<<endl;
    cout<< "\t\t*          Version:   v_1.0               *"<<endl;
    cout<< "\t\t*          Datetime:  Nov. 1              *"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t+-----------------------------------------+"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t*      https://github.com/cjstudio        *"<<endl;
    cout<< "\t\t*      http://www.cjstudio.org            *"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t+*****************************************+"<<endl;
    gotoXY(1,24);
    for(int i =2;i<80;i++)
    {
        cout<<">";
        Sleep(25);
        gotoXY(i-1,24);
        cout<<"==";
    }
    Sleep(1000);
    return MAIN_IFACE;
}
int EmployeeManager::interBye()
{
    return MAIN_IFACE;
}
int EmployeeManager::interMain()
{
    system("cls");
    int x=22,y=11;
    int id=1;
    gotoXY(1,5);
    cout<< "\t\t+*********************************************+"<<endl;
    cout<< "\t\t*                                             *"<<endl;
    cout<< "\t\t*           欢迎使用本职工管理系统            *"<<endl;
    cout<< "\t\t*                                             *"<<endl;
    cout<< "\t\t+*********************************************+"<<endl;
    cout<< "\t\t*                                             *"<<endl;
    cout<< "\t\t*    1.修改职工信息      2.查询职工信息       *"<<endl;
    cout<< "\t\t*    3.删除职工信息      4.添加职工信息       *"<<endl;
    cout<< "\t\t*    5.计算职工工资      6.计算职工奖金       *"<<endl;
    cout<< "\t\t*    7.保存工资信息      8.显示所有职工信息   *"<<endl;
    cout<< "\t\t*                                             *"<<endl;
    cout<< "\t\t+---------------------------------------------+"<<endl;
    cout<< "\t\t*       方向键选择  回车确定  Esc退出         *"<<endl;
    cout<< "\t\t+*********************************************+"<<endl;
    do
    {
        id=(y-11)*2+(x==22?1:2);
        gotoXY(1,24);
        cout<<"x="<<x<<"\ty="<<y<<"\tid="<<id<<endl;
        gotoXY(x,y);
        int c1 = getch();
        if(c1==224) // 方向键的处理
        {
            int c2 = getch();
            switch(c2)
            {
            case KEY_DOWN:
                y=y==14?11:y+1;
                break;
            case KEY_UP:
                y=y==11?14:y-1;
                break;
            case KEY_RIGHT:
            case KEY_LEFT:
                x=x==22?42:22;
                break;
            }
        }
        else
        {
            switch(c1)
            {
            case KEY_NUM1:
                return this->interUpdate();
                break;
            case KEY_NUM2:
                return this->interSelect();
                break;
            case KEY_NUM3:
                return this->interDelete();
                break;
            case KEY_NUM4:
                return this->interAdd();
                break;
            case KEY_NUM5:
                return this->interComputeWage();
                break;
            case KEY_NUM6:
                return this->interComputeSalary();
                break;
            case KEY_NUM7:
                this->save();
                break;
            case KEY_NUM8:
                this->interShowAll();
                break;
            case KEY_ENTER:
                switch(id)
                {
                case 1:
                    return this->interUpdate();
                    break;
                case 2:
                    return this->interSelect();
                    break;
                case 3:
                    return this->interDelete();
                    break;
                case 4:
                    return this->interAdd();
                    break;
                case 5:
                    return this->interComputeWage();
                    break;
                case 6:
                    return this->interComputeSalary();
                    break;
                case 7:
                    this->save();
                    break;
                case 8:
                    return this->interShowAll();
                    break;
                }
                break;
            case KEY_ESC:
                break;
            default:
                break;
            }
        }
    }while(1);

    return MAIN_IFACE;
}
int EmployeeManager::interAdd()
{
    system("cls");
    system("color 1f");
    gotoXY(1,2);
    int line1_w=0, h=33;
    int type_site_x[]={33,41,50};
    cout<< "\t\t+*****************************************+"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t*                 添加职工                *"<<endl;
    cout<< "\t\t*                                         *"<<endl;
    cout<< "\t\t+*****************************************+"<<endl;
    cout<< "\t\t*    Type     | *Worker  Manager  Saler   *"<<endl;
    cout<< "\t\t*    Name     |                           *"<<endl;
    cout<< "\t\t*    Age      |                           *"<<endl;
    cout<< "\t\t*    Sex      |                           *"<<endl;
    cout<< "\t\t*    Worktime |                           *"<<endl;
    cout<< "\t\t*    Grade    |                           *"<<endl;
    cout<< "\t\t*    Tired    |                           *"<<endl;
    cout<< "\t\t*    Wage     |                           *"<<endl;
    cout<< "\t\t*    Salary   |                           *"<<endl;
    cout<< "\t\t*    Marriage |                           *"<<endl;
    cout<< "\t\t*    Marriage |                           *"<<endl;
    cout<< "\t\t*    Marriage |                           *"<<endl;
    cout<< "\t\t*    Marriage |                           *"<<endl;
    cout<< "\t\t+-----------------------------------------+"<<endl;
    cout<< "\t\t* 方向键选择  空格重写该项  回车确认该项  *"<<endl;
    cout<< "\t\t* Ctrl+S添加  Ctrl+L重写所有   ESC返回    *"<<endl;
    cout<< "\t\t+*****************************************+"<<endl;
    gotoXY(33,7);
    do{
        int c1, c2 ;
        if(h == 8)
        {
            c1 = getch();
            if(224 == c1)
            {
                c2 = getch();
                switch(c2)
                {
                case KEY_UP:
                    break;
                case KEY_DOWN:
                    break;
                case KEY_LEFT:
                    line1_w += 1;
                    line1_w = line1_w%3;
                    gotoXY(type_site_x[line1_w],h);
                    break;
                case KEY_RIGHT:
                    break;
                default:
                    break;
                }
            }
        }
    }while(1);
    return MAIN_IFACE;
}
int EmployeeManager::interUpdate()
{
    return MAIN_IFACE;
}
int EmployeeManager::interDelete()
{
    return MAIN_IFACE;
}
int EmployeeManager::interSelect()
{
    return MAIN_IFACE;
}
int EmployeeManager::interHelp()
{
    return MAIN_IFACE;
}
int EmployeeManager::interComputeWage()
{
    return MAIN_IFACE;
}
int EmployeeManager::interComputeSalary()
{
    return MAIN_IFACE;
}
int EmployeeManager::interShowAll()
{
    return MAIN_IFACE;
}
int EmployeeManager::interSave()
{
    //this->save();
    return MAIN_IFACE;
}

// 功能函数
int EmployeeManager::save()
{
    ofstream out("employee.cjdb");
    if (out.is_open())
    {
        for (i_emp = e->begin(); i_emp != e->end(); ++i_emp)
        {
            // 记录职工信息
            ;
        }
        out.close();
    }
    return 0;
}

// 自定义系统函数
void EmployeeManager::gotoXY(int x, int y)
{
    COORD pos;
    pos.X = x - 1;
    pos.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
