//
// Created by zengp on 2018/1/27.
//

#ifndef MYCPPEXERCISE_STOCK_H
#define MYCPPEXERCISE_STOCK_H

#include <string>

class Stock
{

private:
    std::string company_;
    long shares_;
    double share_val_;
    double total_val;

    // 内联
    void set_tot()
    { total_val = shares_ * share_val_; }

public:
    // constructor
    // explicit 不允许隐式自动类型转换
    Stock(const std::string &company = "stock", long shares = 6, double share_val = 10.4);

    // destructor
    ~Stock();

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    // const成员函数，防止调用对象被修改
    void show() const;

    const Stock &topVel(const Stock &s) const;

    // operator overload
    Stock operator+(const Stock &s) const;

    Stock operator*(double d) const;

    // friend function
    friend Stock operator*(double d, const Stock &s);

    friend std::ostream &operator<<(std::ostream &os, const Stock &s);

};

#endif //MYCPPEXERCISE_STOCK_H
