//
// Created by zengp on 2018/2/2.
//
#include <iostream>
#include "acctabc.h"

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

//--------------------------------------------------------------
AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Desposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; desposit is cancelled. \n";
    else
        balance += amt;
}

// 纯虚函数的定义（也可以不定义）
void AcctABC::Withdraw(double amt)
{ balance -= amt; }

AcctABC::Formatting AcctABC::SetFormat() const
{
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(AcctABC::Formatting &f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

//------------------------------------------------------------
// Brass

void Brass::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive; Withdrawal is cancelled. \n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds ypur balance;\n"
             << "Withdrawal is cancelled. \n";
}

void Brass::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "Brass client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Blance: $" << Balance() << endl;
    Restore(f);
}

//---------------------------------------------------
// BressPlus

BrassPlus::BrassPlus(const std::string &s, long an,
                     double bal, double ml, double r)
        : AcctABC(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
        : AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 纯虚函数
void BrassPlus::ViewAcct() const
{
    Formatting f = SetFormat();
    cout << "BrassPluss client: " << FullName() << endl;
    cout << "Account Number: " << AcctNum() << endl;
    cout << "Blance: $" << Balance() << endl;
    cout << "Max loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << rate << "%\n";
    Restore(f);
}

// 纯虚函数
void BrassPlus::Withdraw(double amt)
{
    Formatting f = SetFormat();
    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;

        Desposit(amt);
        AcctABC::Withdraw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled\n";

    Restore(f);
}
