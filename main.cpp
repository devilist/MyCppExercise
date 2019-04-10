#include <iostream>
#include "exercise/PlusExercise.h"
#include "primer/PrimerExercise.h"

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

int main() {
    runPlusExercise();
    runPrimeExercise();
    return 0;
}