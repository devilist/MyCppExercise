//
// Created by zengp on 2018/1/29.
//

#include <cstring>
#include "stringwrapper.h"

using std::cout;
using std::cin;

int StringWrapper::num_string = 0;

int StringWrapper::HowMany()
{
    return num_string;
}

StringWrapper::StringWrapper()
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_string++;
    cout << num_string << ": \"" << str << "\" default object created\n";

}

StringWrapper::StringWrapper(const char *s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_string++;
    cout << num_string << ": \"" << str << "\" object created\n";
}

// 复制构造函数
StringWrapper::StringWrapper(const StringWrapper &sw)
{
    // deep copy
    len = sw.len;
    str = new char[len + 1];
    std::strcpy(str, sw.str);
    num_string++;
    cout << num_string << ": \"" << str << "\" copy object created\n";
}

StringWrapper::~StringWrapper()
{
    cout << "\"" << str << "\" object deleted,";
    --num_string;
    cout << num_string << " left\n";
    delete[] str;
}

// 赋值操作符  并不会创建新的对象
StringWrapper &StringWrapper::operator=(const StringWrapper &sw)
{
    if (this == &sw)
        return *this;
    delete[] str;
    len = sw.len;
    str = new char[len + 1];
    std::strcpy(str, sw.str);
    return *this;
}

StringWrapper &StringWrapper::operator=(const char *s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char &StringWrapper::operator[](int i)
{
    return str[i];
}

const char &StringWrapper::operator[](int i) const
{
    return str[i];
}

bool operator<(const StringWrapper &sw1, const StringWrapper &sw2)
{
    return (std::strcmp(sw1.str, sw2.str) < 0);
}

bool operator>(const StringWrapper &sw1, const StringWrapper &sw2)
{
    return sw2 < sw1;
}

bool operator==(const StringWrapper &sw1, const StringWrapper &sw2)
{
    return (std::strcmp(sw1.str, sw2.str) == 0);
}

std::ostream &operator<<(std::ostream &os, const StringWrapper &sw)
{
    os << sw.str;
    return os;
}

std::istream &operator>>(std::istream &is, StringWrapper &sw)
{
    char temp[StringWrapper::CINLIM];
    is.get(temp, StringWrapper::CINLIM);
    if (is) sw = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
