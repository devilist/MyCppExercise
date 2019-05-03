//
// Created by ZengPu on 2019-05-02.
//

#include <vector>
#include <iostream>
#include "h/prime_chapter6.h"


using namespace std;

///////////////////////////////////////////////
// 返回引用的函数
char &getVal(string &str, string::size_type at);

///////////////////////////////////////////////
// 返回数组指针的函数 几种形式

int (*fun(int i))[10] {
    return nullptr;
}

auto fun1(int i) -> int (*)[10]; // 使用尾置返回类型

//using arrT = int[10];
typedef int arrT[10];

arrT *fun2(int i);

////////////////////////////////////////////////
// 函数指针
bool (*f)(const string &, const string &);

// 这是一个返回值是数组指针的函数指针
int (*((*f1)(int i)))[10];

typedef int (*((*f2)(int i)))[];

////////////////////////////////////////////////
// 返回函数指针的函数

int (*f3(int))(int *, int &);

typedef int f4(int *, int &);

using F5 = int(int *, int &);
using F6 = int (*)(int *, int &);

F5 *f5(int, int);

F6 f6(int, int);

////////////////////////////////////////////////
void printError();

void exercise_6() {

    string s("i am a string");
    getVal(s, 4) = 'A';

    cout << s << endl;
    printError();

    f1 = fun;
}


char &getVal(string &str, string::size_type at) {

    cout << str.size() << endl;
//    if (at < str.size()) {
    return str[at];
//    }
}

void printError() {
#ifdef DEBUG
    if (DEBUG) {
        cerr << "Error: " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "Compiled on " << __DATE__
             << " at " << __TIME__ << endl;
    }
#endif
}


vector<string> process() {
    return {"sdsd", "fgg"};
}








