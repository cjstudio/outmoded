#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include "money.h"

class Manager : public Employee
{
private:
    int workHours;  // 月工作时间
    Money profit;   // 部门利润
public:
    Manager();
    Manager(char *n ,int a, int w, char s, int m, int g,int t,int h, double p);
    void setWorkHours(int h);
    int getWorkHours();
    void setProfit(double p);
    Money getProfit();
    Money getWage();
    Money getSalary();
    void print();
};

#endif // MANAGER_H
