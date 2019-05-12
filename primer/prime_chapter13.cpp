//
// Created by ZengPu on 2019-05-04.
//

#include <typeinfo>
#include <vector>
#include <iostream>
#include "h/prime_chapter13.h"
#include "class/HasPtr.h"
#include "class/HasPtr1.h"
#include "class/SalesData.h"

using namespace std;

void classCopy();

void copyControl();

void exercise_13() {
    classCopy();
    copyControl();
}

//  拷贝构造函数 ,拷贝赋值运算符
void classCopy() {
    SalesData salesData0("salesData0", 1, 10);
    SalesData salesData1("salesData1", 2, 15);
    SalesData salesData2 = salesData0;  // 调用了拷贝构造函数
    salesData2 = salesData1;            // 调用了拷贝赋值运算符
    salesData2.setBookNo("salesData2");

    vector<SalesData> v;
    v.push_back(salesData2);  // 调用了拷贝构造函数!!!!!!!!!!!!
    (*v.begin()).setBookNo("salesData_vector");
    (*v.begin()).setUnitSold(18);
}

void copyControl() {
    // 行为像值的类
    HasPtr hasPtr0("hasPtr_0");
    HasPtr hasPtr1("hasPtr_1");
    hasPtr1 = hasPtr0;

    cout << "typeid "<<typeid(hasPtr1).name() << endl;

    // 行为像指针的类
    HasPtr1 hasPtr10("hasPtr1_0");
    HasPtr1 hasPtr100("hasPtr1_00");
    HasPtr1 hasPtr1000("hasPtr1_000");
    HasPtr1 hasPtr11(hasPtr10);
    HasPtr1 hasPtr12("hasPtr1_2");
    hasPtr12 = hasPtr10;


}


