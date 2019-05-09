//
// Created by admin on 2019/5/8.
//

#include <iostream>
#include <memory>
#include "h/prime_chapter12.h"
#include "class/BulkQuote.h"
#include "class/StrBlob.h"

using namespace std;

void sharePtrRun();

void dynamicAlloc();

void exercise_12() {
    sharePtrRun();
    dynamicAlloc();
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

void dynamicAlloc() {
    allocator<string> m_alloc;
    string *const p = m_alloc.allocate(10);
    auto q = p;
    m_alloc.construct(q++, "1");
    m_alloc.construct(q++, 5, 'c');
    m_alloc.construct(q++, "hi");
    cout << *p << endl;
    cout << *(q - 1) << endl;

    // 释放
    while (q != p) {
        m_alloc.destroy(--q);
    }
    m_alloc.deallocate(p, 10);


}
