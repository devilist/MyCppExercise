//
// Created by admin on 2019/5/6.
//

#ifndef MYCPPEXERCISE_BULKQUOTE_H
#define MYCPPEXERCISE_BULKQUOTE_H

#include "Quote.h"

class BulkQuote final : public Quote {

private:
    std::size_t minQty = 0;
    double discount = 0.0;

public:
    BulkQuote() = default;

    BulkQuote(const std::string &book, double sale_price, std::size_t mQ, double discou);

    BulkQuote(const std::string &book, double sale_price);

    double net_price(std::size_t n) const override;

    ~BulkQuote() override;

};


#endif //MYCPPEXERCISE_BULKQUOTE_H
