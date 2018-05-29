// Created by zengp on 2018/1/15.
#include <iostream>
#include <cstring>
#include "h/chapter4.h"

using namespace std;

struct inflatable
{
    std::string name;
    float volume;
    double price;
};

void exercise_string()
{
    cout << "Hello, C++!" << endl;
    string str = "i am string";
    auto *strPoint = new string;
    *strPoint = str;
    cout << "str is: " << str << endl;
    cout << "str point value is: " << *strPoint << endl;
    cout << "str point location is: " << strPoint << endl;
    cout << "str point (int) is: " << (int *) strPoint << endl;
    char strArray[20] = "啊呀呀";
    cout << "str array is " << strArray << endl;
    strcpy(strArray, "傻逼");
    cout << "str array is " << strArray << endl;
}

void exercise_struct()
{
    auto *ps = new inflatable;
    ps->name = "i am a struct pointer";
    ps->volume = 1.6;
    ps->price = 200;
    cout << "\n两种访问结构（指针）成员的方式：\n";
    cout << "ps->name:   " << ps->name << endl;
    cout << "(*ps).name: " << (*ps).name << endl << "\n";
    cout << "结构指针ps的地址： " << ps << endl;
    cout << "ps->name的地址：  " << &(ps->name) << endl;

    cout.setf(ios_base::boolalpha);

    // 释放内存
    delete ps;
}

void exercise4()
{
//    exercise_string();
//    exercise_struct();

}
