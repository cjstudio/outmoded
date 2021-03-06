#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <iostream>
#include <list>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "employee.h"


using namespace std;

class EmployeeManager
{
    typedef list<Employee> LIST_EMP;
    LIST_EMP::iterator i_emp;

    enum SITE_IFACE
    {
        ERROR_IFACE=-2,
        OVER_IFACE=-1,
        START_IFACE=0,
        MAIN_IFACE,
        UPDATE_IFACE,
        SELECT_IFACE,
        DELETE_IFACE,
        ADD_IFACE,
        COMPUTE_WAGE_IFACE,
        COMPUTE_SALARY_IFACE
    };

    enum KEY_ASSI
    {
        KEY_UP=72,
        KEY_DOWN=80,
        KEY_LEFT=77,
        KEY_RIGHT=75,
        KEY_ENTER=13,
        KEY_ESC=27,
        KEY_SPACE=32,
        KEY_NUM0=48,
        KEY_NUM1,
        KEY_NUM2,
        KEY_NUM3,
        KEY_NUM4,
        KEY_NUM5,
        KEY_NUM6,
        KEY_NUM7,
        KEY_NUM8,
        KEY_NUM9,
        KEY_CTRL_L=12,
        KEY_CTRL_S=19
    };

    enum NAME_ID{
        ID_NAME=1,
        ID_AGE,
        ID_WORKTIME,
        ID_SEX,
        ID_MARRIAGE,
        ID_GRADE,
        ID_TIRED,
        ID_WAGE,
        ID_SALARY
    };

private:
    LIST_EMP *e;
    char *file_path;
    int count_manager;
    int count_saler;
    int count_worker;

    int interWel();
    int interBye();
    int interMain();
    int interAdd();
    int interUpdate();
    int interDelete();
    int interSelect();
    int interHelp();
    int interComputeWage();
    int interComputeSalary();
    int interShowAll();
    int interSave();

    // 功能函数
    int save();
//    void deleteEmployee(int index);
//    void updateEmployee(int index);
//    void addEmployee(Employee &e);
//    void operator +(Employee &e);
//    Money computeWage();
//    Money computeSalary();

    // 自定义系统函数
    void gotoXY(int x,int y);

public:
    EmployeeManager();
    ~EmployeeManager();
    int xitongjiemian(int site);
};

#endif // EMPLOYEEMANAGER_H
