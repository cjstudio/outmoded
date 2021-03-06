#include "money.h"

Money::Money()
{
    this->money = 0;
}
Money::Money(double m)
{
    this->money = m;
}
void Money::setValue(double m)
{
    this->money = m;
}
void Money::operator =(double m)
{
    this->money = m;
}
void Money::operator =(Money m)
{
    this->money = m.getMoney();
}
double Money::operator +(double m)
{
    return this->money = m;
}

double Money::operator +(Money m)
{
    return this->money + m.getMoney();
}

double Money::getMoney()
{
    return this->money;
}

Money Money::ValueOf()
{
    Money m( (int)((money*1000+5)/10)*1.0/100 );
    return m;
}

char *Money::toString()
{
    double tmp = (int)((money*1000+5)/10)*1.0/100;
    sprintf(str,"￥%.2f",tmp);
    return str;
}
