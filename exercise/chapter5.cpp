//
// Created by zengp on 2018/1/16.
//

#include <iostream>
#include <ctime>
#include "h/chapter5.h"

using namespace std;

void for_loop()
{
    cout.setf(ios_base::boolalpha);
    for (int i = 0; i < 3; ++i)
    {
        cout << "i = " << i << " bool " << (i > 1) << endl;
    }

    double what[4] = {2.1, 54, 6.32, 5.4};
    for (double &x : what)  // 引用变量 可以修改数组中的值
    {
        x = x + 1;
        cout << x << " ";
    }
    cout << endl;
    cout << what[0] << endl;

}

void while_loop()
{
    clock_t delay = 5 * CLOCKS_PER_SEC;
    clock_t start = clock();
    cout << "start with delay 5 sec: " << endl;
    while (clock() - start < delay);
    cout << "finish! " << endl;

}

void exercise5()
{
    for_loop();
    while_loop();

}