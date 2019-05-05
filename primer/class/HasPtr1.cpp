//
// Created by ZengPu on 2019-05-05.
//

#include <iostream>
#include "HasPtr1.h"

using namespace std;

HasPtr1 &HasPtr1::operator=(const HasPtr1 &p) {

    cout << "copy operator is called, copy " << *p.ps << " to " << *ps
         << endl;

    ++*p.use;
    cout << "*p.use " << *p.use << " *use " << *use << endl;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    cout << "after *use " << *use << endl;

    return *this;
}

HasPtr1::~HasPtr1() {

    if (--*use == 0) {
        delete ps;
        delete use;
    }
}


