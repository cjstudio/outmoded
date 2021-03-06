#include "employee.h"
Employee::Employee()
{
}

Employee::Employee(char *_name, int _age, int _worktime,
                   char _sex, int _marriage, int _grade, int _tired)
{
    this->name = _name;
    this->age = _age;
    this->worktime = _worktime;
    this->sex = _sex;
    this->marriage = _marriage;
    this->grade = _grade;
    this->tired = _tired;
    this->wage = 0.0;
    this->salary = 0.0;
}

void Employee::setName(char *s)
{
    this->name = s;
}
char *Employee::getName()
{
    return this->name;
}
void Employee::setAge(int a)
{
    this->age = a;
}
int Employee::getAge()
{
    return this->age;
}
void Employee::setWorktime(int w)
{
    this->worktime = w;
}

int Employee::getWorktime()
{
    return this->worktime;
}

void Employee::setSex(char s)
{
    this->sex = s;
}

char Employee::getSex()
{
    return this->sex;
}

void Employee::setMarriage(int i)
{
    this->marriage = i;
}

int Employee::getMarriage()
{
    return this->marriage;
}

void Employee::setGrade(int g)
{
    this->grade = g;
}

int Employee::getGrade()
{
    return this->grade;
}

void Employee::setTired(int t)
{
    this->tired = t;
}

int Employee::getTired()
{
    return this->tired;
}

void Employee::setWage(double w)
{
    this->wage = w;
}

double Employee::getWage()
{
    return this->wage.getMoney();
}

void Employee::setSalary(double s)
{
    this->salary = s;
}

double Employee::getSalary()
{
    return this->salary.getMoney();
}

void Employee::print()
{
    ;
}
