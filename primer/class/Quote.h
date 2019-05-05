//
// Created by ZengPu on 2019-05-06.
//

#ifndef MYCPPEXERCISE_QUOTE_H
#define MYCPPEXERCISE_QUOTE_H

#include <iostream>

class Quote {

private:
    std::string bookNo;

protected:
    double price = 0.0;

public:
    Quote() = default;

    Quote(const std::string &book, double sale_price) :
            bookNo(book), price(sale_price) {}

    std::string isbn() const {
        return bookNo;
    }

    virtual double net_price(std::size_t n) const {
        return n * price;
    }

    virtual ~Quote() = default;

};


#endif //MYCPPEXERCISE_QUOTE_H
