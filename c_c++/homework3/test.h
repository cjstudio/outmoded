#ifndef TEST_H
#define TEST_H

#include "money.h"
#include <iostream>

using namespace std;

void testMoney1()
{
    cout << "Test class Money Start" <<endl;
    Money m(2.12543);
    cout << "m.getMoney = " << m.getMoney() << endl ;
    cout <<"m.toString = "<< m.toString() << endl;
    m = 3.14159;
    cout <<"m.toString = "<< m.toString() << endl;
    Money n;
    n = m;
    cout << "n.getMoney = "<<n.getMoney() << endl;
    cout << "n.ValueOf().getMoney = " << n.ValueOf().getMoney() << endl;
    cout << "Test class Money Over" <<endl;
}



#endif // TEST_H
