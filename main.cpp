#include <iostream>
#include "exercise/h/chapter4.h"
#include "exercise/h/chapter5.h"
#include "exercise/h/chapter6.h"
#include "exercise/h/chapter7.h"
#include "exercise/h/chapter8.h"
#include "exercise/h/chapter9.h"
#include "exercise/h/chapter10.h"
#include "exercise/h/chapter12.h"
#include "exercise/h/chapter14.h"

using namespace std;

//---------------------------------------------------------------------------------
// 静态持续性，外部连结特性

// 定义声明 defining declaration (definition)
// 分配存储空间
int a_int_in_main = 100;
// 定义声明 referencing declaration (declaration)
// 不分配存储空间，引用已有变量(定义在chapter9.cpp中)
extern int a_int_in_exercise9;

// 静态持续性，内部连结特性  static 或 const
// 如果希望const变量被外部文件访问，需要用 extern 修饰
static int b_int_main = 90;
const int c_int_main = 10;
extern const int d_int_main = 15; // 可以被外部文件访问

//----------------------------------------------------------------------------------

int main()
{
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    exercise9();
    exercise10();
    exercise12();
    exercise14();
    return 0;
}