#include "saler.h"

Saler::Saler()
{
}
Saler::Saler(char *n ,int a, int w, char s, int m, int g,int t, double p)
    :Employee(n,a,w,s,m,g,t)
{
    this->profit = p;
}
void Saler::setProfit(double p)
{
    this->profit = p;
}
Money Saler::getProfit()
{
    return this->profit;
}
Money Saler::getSalary()
{
    return this->salary;
}

void Saler::print()
{
    ;
}
