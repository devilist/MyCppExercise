//
// Created by zengp on 2018/2/4.
//

#ifndef MYCPPEXERCISE_STUDENT_H
#define MYCPPEXERCISE_STUDENT_H


#include <valarray>
#include <string>

class Student
{
private:
    typedef std::valarray<double> ArrayDb;

    std::string name;
    ArrayDb scores;

    std::ostream &arr_out(std::ostream &os) const;

public:
    Student() : name("Null Student"), scores()
    {};

    explicit Student(const std::string &s) : name(s), scores()
    {};

    explicit Student(int n) : name("Null Student"), scores(n)
    {};

    Student(const std::string &s, int n) : name(s), scores(n)
    {};

    Student(const std::string &s, ArrayDb &a) : name(s), scores(a)
    {};

    Student(const char *str, const double *pd, int n) : name(str), scores(pd, n)
    {};

    ~Student()
    {};

    double Avarage() const;

    const std::string &Name() const;

    double &operator[](int i);

    double operator[](int i) const;

    friend std::istream &operator>>(std::istream &is, Student &stu);

    friend std::istream &getline(std::istream &is, Student &stu);

    friend std::ostream &operator<<(std::ostream &os, const Student &stu);

};


#endif //MYCPPEXERCISE_STUDENT_H
