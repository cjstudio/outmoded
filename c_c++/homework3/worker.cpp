#include "worker.h"

Worker::Worker()
{
}
Worker::Worker(char *n ,int a, int w, char s, int m, int g,int t,int h)
    :Employee(n,a,w,s,m,g,t)
{
    this->workHours = h;
//    Employee::Employee(char *_name, int _age, int _worktime,
//                       char _sex, int _marriage, int _grade, int _tired)
}

int Worker::getWorkHours()
{
    return this->workHours;
}
void Worker::setWorkHours(int h)
{
    this->workHours = h;
}
void Worker::print()
{
    ;
}
