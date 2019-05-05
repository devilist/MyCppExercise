//
// Created by ZengPu on 2019-05-02.
//

#ifndef MYCPPEXERCISE_SALESDATA_H
#define MYCPPEXERCISE_SALESDATA_H

#include <iostream>


class SalesData {

    friend std::istream &read(std::istream &is, SalesData &data);

    friend std::ostream &print(std::ostream &os, const SalesData &data);

private:
    static int defaultP;
    std::string bookNo;
    unsigned unitSold = 0;
    double revenue = 0.0;

    double avgPrice() const {
        return unitSold ? revenue / unitSold : 0;
    }

public:
//    SalesData() = default;
    SalesData();

    // 拷贝构造函数
    SalesData(const SalesData &salesData);

    SalesData(const std::string &s, unsigned n, double p);

    // 禁用构造函数隐式转换
    explicit SalesData(const std::string &s);

    explicit SalesData(std::istream &);

    // 拷贝合成运算符
    SalesData &operator=(const SalesData &rhs);

    ~SalesData();

    ///////////////////////////////////////////////////////////////

    void setUnitSold(unsigned sold);

    void setBookNo(std::string s);

    SalesData &combine(const SalesData &);

    std::string isbn() const {
        return bookNo;
    }


};


#endif //MYCPPEXERCISE_SALESDATA_H
