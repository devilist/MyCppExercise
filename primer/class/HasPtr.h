//
// Created by admin on 2019/5/5.
//

#ifndef MYCPPEXERCISE_HASPTR_H
#define MYCPPEXERCISE_HASPTR_H


// 定义行为像值的类

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

    // 移动构造函数
    HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
        p.ps = nullptr;
    }

    HasPtr &operator=(const HasPtr &p);

    HasPtr &operator=(HasPtr p) {
//        std::swap(*this, p);
        return *this;
    }


    ~HasPtr() { delete ps; };
};


#endif //MYCPPEXERCISE_HASPTR_H
