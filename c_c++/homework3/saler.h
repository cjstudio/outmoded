#ifndef SALER_H
#define SALER_H

#include "employee.h"

class Saler : public Employee
{
private:
    Money profit;   // 部门利润
public:
    Saler();
    Saler(char *n , int a, int w, char s, int m, int g, int t, double p);
    void setProfit(double p);
    Money getProfit();
    Money getSalary();
    void print();
};

#endif // SALER_H
