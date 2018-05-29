//
// Created by zengp on 2018/1/19.
//

#include <iostream>
#include "h/chapter7.h"

const int MAX = 3;

int fill_array(double [], int limit);

void show_array(const double [], int n);

void revalue(double r, double [], int n);

void array_function_exercise();

void exercise7()
{
//    array_function_exercise();
}

void array_function_exercise()
{
    using namespace std;
    double property[MAX];
    int size = fill_array(property, MAX);
    show_array(property, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input ,Please enter a number: ";
        }
        revalue(factor, property, size);
        show_array(property, size);
    }
    cout << "Done. \n";
    cin.get();
}


int fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> temp;
        if (!cin) // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input \n";
            break;
        } else if (temp < 0)
            break;
        ar[i] = temp;
    }
    return i;
}

void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; ++i)
        cout << "Property #" << i + 1 << ": $" << ar[i] << endl;
}

void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; ++i)
        ar[i] *= r;
}


