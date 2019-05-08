//
// Created by admin on 2019/5/8.
//

#include <iostream>
#include "StrBlobPtr.h"

using namespace std;

std::string &StrBlobPtr::deref() const {
    shared_ptr<vector<string>> ret = check(curr, "derference past end");
    return (*ret)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment");
    ++curr;
    return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &m) const {
    shared_ptr<vector<string>> ret = wptr.lock();
    if (!ret) {
        return nullptr;
    } else if (i >= ret->size()) {
        cout << "out of bound!" << endl;
        return nullptr;
    }
    return ret;
}
