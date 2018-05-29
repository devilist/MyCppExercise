//
// Created by zengp on 2018/1/27.
//

#include <iostream>
#include "h/chapter10.h"
#include "class/stock.h"
#include "class/stringwrapper.h"

void showStock();

void showStringWrapper();


void exercise10()
{
//    showStock();
//    showStringWrapper();
}


void showStock()
{
    Stock fluffy = Stock("fluffy", 20, 12.5);
    fluffy.buy(15, 21.14);
    fluffy.sell(43, 13.4);
    fluffy.update(43.2);
    fluffy.show();

    Stock stock0("stock0", 260);

    Stock *stock1 = new Stock("stock1");
    Stock stock2;
    Stock *stock3 = new Stock;
//    fluffy = *stock3;
    // c++11的初始化
    Stock stock4 = {"stock4", 34, 23};
    Stock stock5{"stock5", 34, 23};
    stock2 = stock4 + stock5;
    stock2 = stock2 * 1.2;
    stock2 = 1.3 * stock2;

    std::cout << "\nprint stock2:\n" << stock2;


    delete stock1, stock3;
}

void showStringWrapper()
{
    StringWrapper wrapper0 = StringWrapper("wrapper0");
    StringWrapper wrapper1;

    std::cout << "wrapper0 : " << wrapper0 << "; address : " << &wrapper0 << "\n";
    std::cout << "wrapper1 : " << wrapper1 << "; address : " << &wrapper1 << "\n";

    wrapper1 = wrapper0;

    std::cout << "wrapper1 : " << wrapper1 << "; address : " << &wrapper1 << "\n";

    StringWrapper wrapper2 = wrapper1;
    std::cout << "wrapper2 : " << wrapper2 << "; address : " << &wrapper2 << "\n";

}


