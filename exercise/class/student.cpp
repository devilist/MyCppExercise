//
// Created by zengp on 2018/2/4.
//

#include <iostream>
#include "student.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

std::ostream &Student::arr_out(std::ostream &os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    } else os << "empty array";

    return os;
}

double Student::Avarage() const
{
    if (scores.size() > 0)
        return scores.sum() / scores.size();
    return 0;
}

const std::string &Student::Name() const
{
    return name;
}

double &Student::operator[](int i)
{
    return scores[i];
}

double Student::operator[](int i) const
{
    return scores[i];
}

std::istream &operator>>(std::istream &is, Student &stu)
{
    is >> stu.name;
    return is;
}

std::istream &getline(std::istream &is, Student &stu)
{
    // use string friend getline
    getline(is, stu.name);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Student &stu)
{
    os << "Score for " << stu.name << ":\n";
    stu.arr_out(os);
    return os;
}
