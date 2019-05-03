//
// Created by ZengPu on 2019-05-02.
//

#include "SalesData.h"

int SalesData::defaultP = 100;

SalesData::SalesData() : SalesData("", 0, 0) {

}

SalesData::SalesData(const std::string &s, unsigned n, double p)
        : bookNo(s), unitSold(n), revenue(p * n) {
    // 上面是通过构造函数初始化（构造函数初始值列表）
    // 下面这三句是赋值过程，而不是初始化
//    bookNo = s;
//    unitSold = n;
//    revenue = n * p;
}

SalesData::SalesData(const std::string &s)
        : SalesData(s, 0, 0) {

}

SalesData::SalesData(std::istream &is) : SalesData() {
    read(is, *this);
}


SalesData &SalesData::combine(const SalesData &rhs) {
    unitSold += rhs.unitSold;
    revenue += rhs.revenue;

    return *this;
}


std::istream &read(std::istream &is, SalesData &data) {
    double price = 0;
    is >> data.bookNo >> data.unitSold >> price;
    data.revenue = price * data.unitSold;
    return is;
}

std::ostream &print(std::ostream &os, const SalesData &data) {
    os << data.isbn() << " "
       << data.unitSold << " "
       << data.revenue << " "
       << data.avgPrice();
    return os;
}
