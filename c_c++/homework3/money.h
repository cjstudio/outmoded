#ifndef MONEY_H
#define MONEY_H

#include <stdio.h>

class Money
{
private:
    double money;
	char str[20];
public:
    Money();
    Money(double m);
    double getMoney();
	void setValue(double m);
    void operator =(double m);
    void operator =(Money m);
    double operator +(double m);
    double operator +(Money m);
    Money ValueOf();
    char *toString();
};

#endif // MONEY_H
