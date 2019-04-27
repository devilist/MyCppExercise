//
// Created by zengp on 2018/1/25.
// 内存模型
// 命名空间
//

#include <iostream>
#include "h/chapter9.h"

using std::cout;
using std::endl;

//---------------------------------------------------------------------------------
// 静态持续性，外部连结特性

// 定义声明 defining declaration (definition)
// 分配存储空间
int a_int_in_exercise9 = 100;

// 定义声明 referencing declaration (declaration)
// 不分配存储空间，引用已有变量(定义在main.cpp中)
extern int a_int_in_main;

// 静态持续性，内部连结特性

static int b_int_exercise9 = 80;

extern int b_int_main; // 访问不到main.cpp中的 b_int_main
extern int c_int_main; // 访问不到main.cpp中的 c_int_main
extern const int d_int_main; // 可以访问到main.cpp中的 d_int_main

//----------------------------------------------------------------------------------

void update();

void exercise9()
{
    update();
}

void update()
{
    a_int_in_main++;
    cout << ::a_int_in_main << endl;
    cout << ::d_int_main << endl;

}
