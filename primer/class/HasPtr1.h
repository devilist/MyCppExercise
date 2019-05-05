//
// Created by ZengPu on 2019-05-05.
//

#ifndef MYCPPEXERCISE_HASPTR1_H
#define MYCPPEXERCISE_HASPTR1_H

// 定义行为像指针的类

class HasPtr1 {

private:
    std::string *ps;
    int i;
    std::size_t *use;

public:

    HasPtr1(const std::string &s = std::string())
            : ps(new std::string(s)),
              i(0),
              use(new std::size_t(1)) {};

    // 拷贝
    HasPtr1(const HasPtr1 &p)
            : ps(new std::string(*p.ps)), i(p.i), use(p.use) {
        std::cout << "this use " << use
                  << " p use " << p.use << std::endl;
        ++*use;
    }

    HasPtr1 &operator=(const HasPtr1 &p);

    ~HasPtr1();
};


#endif //MYCPPEXERCISE_HASPTR1_H
