//
// Created by ZengPu on 2019-05-06.
//

#include "h/prime_chapter15.h"
#include "class/Quote.h"
#include "class/BulkQuote.h"

void copyPtr(BulkQuote *bulkQuote);

void exercise_15() {

    BulkQuote quote("book1", 12.34);

    quote.net_price(3);
    copyPtr(&quote);
    std::cout << "quote: " << &quote << std::endl;

}

void copyPtr(BulkQuote *bulkQuote) {
    BulkQuote *b{nullptr};
    b = bulkQuote;
    b = nullptr;
    std::cout << "b: " << b << std::endl;
    std::cout << "bulkQuote: " << bulkQuote << std::endl;
}