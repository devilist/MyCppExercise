//
// Created by admin on 2019/5/6.
//

#include <iostream>
#include "BulkQuote.h"

using namespace std;


BulkQuote::BulkQuote(const std::string &book, double sale_price) : Quote(book, sale_price) {

}

BulkQuote::BulkQuote(const std::string &book, double sale_price, std::size_t mQ, double discou)
        : Quote(book, sale_price), minQty(mQ), discount(discou) {

}

double BulkQuote::net_price(std::size_t n) const {
    cout << "BulkQuote net_price is called" << endl;
    if (n > minQty) {
        return n * (1 - discount) * price;
    } else
        return Quote::net_price(n);
}

BulkQuote::~BulkQuote() {
    cout << "BulkQuote destructor is called" << endl;
}

