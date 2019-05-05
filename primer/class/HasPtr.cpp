//
// Created by admin on 2019/5/5.
//

#include <iostream>
#include "HasPtr.h"

using namespace std;

HasPtr &HasPtr::operator=(const HasPtr &p) {

    cout << "copy operator is called, copy " << *p.ps << " to " << *ps
         << endl;

    ////////////////////////////////
    // 错误的顺序
    // delete ps;
    // ps = new string(*p.ps);
    // i = p.i;
    /////////////////////////////////

    string *newp = new string(*p.ps);
    delete ps;
    ps = newp;
    i = p.i;

    return *this;
}
