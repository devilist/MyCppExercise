//
// Created by admin on 2019/5/5.
//

#ifndef MYCPPEXERCISE_HASPTR_H
#define MYCPPEXERCISE_HASPTR_H


class HasPtr {

private:
    std::string *ps;
    int i;

public:

    HasPtr(const std::string &s = std::string())
            : ps(new std::string(s)), i(0) {};

    // 拷贝
    HasPtr(const HasPtr &p)
            : ps(new std::string(*p.ps)), i(p.i) {};

    HasPtr &operator=(const HasPtr &p);

    ~HasPtr() { delete ps; };
};


#endif //MYCPPEXERCISE_HASPTR_H
