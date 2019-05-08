//
// Created by admin on 2019/5/8.
//

#include <iostream>
#include <memory>
#include "h/prime_chapter12.h"
#include "class/BulkQuote.h"

using namespace std;

void sharePtrRun();

void exercise_12() {
    sharePtrRun();
}

void sharePtrRun() {
    std::shared_ptr<int> shareInt = make_shared<int>(8);
//    shared_ptr<BulkQuote> spBQ = make_shared<BulkQuote>(BulkQuote("book", 12.4));
    shared_ptr<BulkQuote> spBQ = make_shared<BulkQuote>("book", 12.4);
    shared_ptr<BulkQuote> spBQ1 = shared_ptr<BulkQuote>(spBQ);
    shared_ptr<BulkQuote> spBQ2(spBQ1);
    shared_ptr<BulkQuote> spBQ3 = shared_ptr<BulkQuote>(new BulkQuote("book3", 454.3));

//    std::map<string, shared_ptr<BulkQuote>> mMap;
    cout << *shareInt.get() << endl;
    cout << (*spBQ).isbn() << endl;
    cout << spBQ.get()->isbn() << endl;
    cout << spBQ1.get()->isbn() << endl;
    cout << spBQ.unique() << " " << spBQ.use_count() << endl;
    cout << spBQ1.unique() << " " << spBQ1.use_count() << endl;
    cout << spBQ2.unique() << " " << spBQ2.use_count() << endl;
}
