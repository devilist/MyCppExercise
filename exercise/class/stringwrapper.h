//
// Created by zengp on 2018/1/29.
//
#include <iostream>

#ifndef MYCPPEXERCISE_STRINGWRAPER_H
#define MYCPPEXERCISE_STRINGWRAPER_H

class StringWrapper
{
private:
    char *str;
    int len;
    static int num_string;
    static const int CINLIM = 80; // cin input limit

public:
    // constructor
    StringWrapper(const char *s);

    // default constructor
    StringWrapper();

    // 复制构造函数 copy constructor
    StringWrapper(const StringWrapper &sw);

    // destructor
    ~StringWrapper();

    int length()
    { return len; }

    // overload operator methods
    // 赋值操作符  并不会创建新的对象
    StringWrapper &operator=(const StringWrapper &sw);

    StringWrapper &operator=(const char *);

    char &operator[](int i);

    const char &operator[](int i) const;

    // overload operator friends
    friend bool operator<(const StringWrapper &sw1, const StringWrapper &sw2);

    friend bool operator>(const StringWrapper &sw1, const StringWrapper &sw2);

    friend bool operator==(const StringWrapper &sw1, const StringWrapper &sw2);

    friend std::ostream &operator<<(std::ostream &os, const StringWrapper &sw);

    friend std::istream &operator>>(std::istream &is, StringWrapper &sw);

    // static function
    static int HowMany();
};

#endif //MYCPPEXERCISE_STRINGWRAPER_H
