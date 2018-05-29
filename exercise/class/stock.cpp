//
// Created by zengp on 2018/1/27.
//

#include <iostream>
#include "stock.h"

Stock::Stock(const std::string &company, long shares, double share_val)
{
    std::cout << "Stock::constructor " << "company_ " << company << std::endl;
    company_ = company;
    shares_ = shares;
    share_val_ = share_val;
}

Stock::~Stock()
{
    std::cout << "Stock::destructor  Bye~ " << company_ << std::endl;

}

void Stock::buy(long num, double price)
{
    std::cout << "Stock::buy" << std::endl;
}

void Stock::sell(long num, double price)
{
    std::cout << "Stock::sell" << std::endl;
}

void Stock::update(double price)
{
    std::cout << "Stock::update" << std::endl;
}

void Stock::show() const
{
    std::cout << "Stock::show" << std::endl;
}

const Stock &Stock::topVel(const Stock &s) const
{
    if (s.total_val > total_val)
        return s;
    else return *this;
}

Stock Stock::operator+(const Stock &s) const
{
    Stock sum;
    sum.company_ = company_ + "_and_" + s.company_;
    sum.shares_ = shares_ + s.shares_;
    sum.share_val_ = share_val_ + s.share_val_;
    sum.total_val = total_val + s.total_val;
    return sum;
}

Stock Stock::operator*(double d) const
{
    Stock result = *this;
    result.company_ = company_ + "_*";
    result.share_val_ = share_val_ * d;
    return result;
}

Stock operator*(double d, const Stock &s)
{
    Stock result = s;
    result.company_ = s.company_ + "_friend*";
    return result * d;
}

std::ostream &operator<<(std::ostream &os, const Stock &s)
{
    os << "-------------------------------------------\n";
    os << "company: " << s.company_ << "\nshares: " << s.shares_;
    os << "\n-------------------------------------------\n";

    return os;

}


