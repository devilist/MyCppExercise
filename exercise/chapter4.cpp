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
    char strArray[20] = "��ѽѽ";
    cout << "str array is " << strArray << endl;
    strcpy(strArray, "ɵ��");
    cout << "str array is " << strArray << endl;
}

void exercise_struct()
{
    auto *ps = new inflatable;
    ps->name = "i am a struct pointer";
    ps->volume = 1.6;
    ps->price = 200;
    cout << "\n���ַ��ʽṹ��ָ�룩��Ա�ķ�ʽ��\n";
    cout << "ps->name:   " << ps->name << endl;
    cout << "(*ps).name: " << (*ps).name << endl << "\n";
    cout << "�ṹָ��ps�ĵ�ַ�� " << ps << endl;
    cout << "ps->name�ĵ�ַ��  " << &(ps->name) << endl;

    cout.setf(ios_base::boolalpha);

    // �ͷ��ڴ�
    delete ps;
}

void exercise4()
{
    exercise_string();
    exercise_struct();

}
