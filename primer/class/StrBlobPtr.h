//
// Created by admin on 2019/5/8.
//

#ifndef MYCPPEXERCISE_STRBLOBPTR_H
#define MYCPPEXERCISE_STRBLOBPTR_H


#include <memory>
#include <vector>

#include "StrBlob.h"

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}

    StrBlobPtr(StrBlob &a, size_t sz = 0)
            : wptr(a.data), curr(sz) {};

    std::string &deref() const;

    StrBlobPtr &incr();

private:
    std::weak_ptr<std::vector<std::string>> wptr;

    std::size_t curr;

    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
};


#endif //MYCPPEXERCISE_STRBLOBPTR_H
