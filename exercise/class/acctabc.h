//
// Created by zengp on 2018/2/2.
//

#ifndef MYCPPEXERCISE_ACCTABC_H
#define MYCPPEXERCISE_ACCTABC_H


#include <iostream>
#include <string>

// 抽象基类
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };

    const std::string &FullName() const
    { return fullName; };

    long AcctNum() const
    {
        return acctNum;
    }

    Formatting SetFormat() const;

    void Restore(Formatting &f) const;

public:
    AcctABC(const std::string &s = "Nullbody",
            long an = -1, double bal = 0.0);

    void Desposit(double amt); // 存钱

    // 纯虚函数 pure virtual function
    virtual void Withdraw(double amt) = 0;

    virtual void ViewAcct() const = 0;

    virtual ~AcctABC()
    {};

    // 内联
    double Balance() const
    { return balance; };

};

class Brass : public AcctABC
{
public:
    Brass(const std::string &s = "Nullbody",
          long an = -1, double bal = 0.0) : AcctABC(s, an, bal)
    {};

    virtual void Withdraw(double amt);

    virtual void ViewAcct() const;

    virtual ~Brass()
    {};
};

class BrassPlus : public AcctABC
{
private:
    double maxLoan, rate, owesBank;
public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500, double r = 0.10);

    BrassPlus(const Brass &ba, double ml = 500, double r = 0.1);

    virtual void Withdraw(double amt);

    virtual void ViewAcct() const;

    void ResetMax(double m)
    { maxLoan = m; };

    void ResetRate(double r)
    { rate = r; };

    void ResetOwes()
    { owesBank = 0; };
};

#endif //MYCPPEXERCISE_ACCTABC_H
