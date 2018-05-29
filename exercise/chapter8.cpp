//
// Created by zengp on 2018/1/21.
// 内联函数
// 引用变量
// 函数重载
// 函数模板(泛型)
//

#include <iostream>
#include "h/chapter8.h"

using namespace std;

double refcube(const double &);

void exercise_ref_for_fun();

void show_array(const int[], int);

struct job
{
    char name[40];
    double salary;
    int floor;

};

// or class T
// original template 原始模板函数
template<typename T>
void exChange(T &a, T &b);

// overload template 原始模板函数的一个重载。函数的特征标(signature)必须不同
template<typename T>
void exChange(T *a, T *b, int n);

// explicit specialization  显式具体化
template<>
void exChange<float>(float &, float &);

template<>
void exChange<job>(job &, job &);


template<class T>
T Add(T a, T b);

// explicit instantiation for char  显式实例化
template char Add<char>(char, char);

void exercise_for_template();

void exercise8()
{
//    exercise_ref_for_fun();
//    exercise_for_template();

}

//---------------------------------------------------------------
// reference argument
//---------------------------------------------------------------
void exercise_ref_for_fun()
{
    double side = 3.0;
    cout << side << endl;
    cout << refcube(side) << endl;
    cout << side << endl;
}

double refcube(const double &ra)
{
    return ra * ra * ra;
}


//---------------------------------------------------------------
// template func
//---------------------------------------------------------------
void exercise_for_template()
{
    int a = 1, b = 6;
    exChange(a, b);  // match original template
    cout << "a= " << a << " , " << "b = " << b << endl;

    // overload template
    int arr1[3] = {1, 345, 53};
    int arr2[3] = {355, 21, 89};
    cout << endl;
    cout << "before change arr1:";
    show_array(arr1, 3);
    cout << "before change arr2:";
    show_array(arr2, 3);
    exChange(arr1, arr2, 3); // match overload exChange(T *a, T *b, int n)
    cout << " after change arr1:";
    show_array(arr1, 3);
    cout << " after change arr2:";
    show_array(arr2, 3);
    cout << endl;

    // explicit specialization 显式具体化
    float fa = 1.443, fb = 343.13;
    job job1 = {"wang_le", 130.23, 23};
    job job2 = {"shan_bi", 363.75, 17};
    exChange(fa, fb);             //  match specialization exChange<float>(float &, float &)
    exChange(job1, job2);         //  match specialization exChange<job>(job &, job &)
    cout << endl;

    // instantiation 模板函数实例化
    char ca = 'f', cb = 'a';
    Add(fa, fb);                  // implicit instantiation for float
    Add<float>(a, fb);            // explicit instantiation for float
    Add(ca, cb);                  // explicit instantiation for char

}

template<typename T>
void exChange(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void exChange(T a[], T b[], int n)
{
    T temp;
    for (int i = 0; i < n; ++i)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<>
void exChange(float &a, float &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

template<>
void exChange(job &j1, job &j2)
{
    cout << "before change job:\n";
    cout << "j1: " << j1.name << " " << j1.salary << " " << j1.floor << endl;
    cout << "j2: " << j2.name << " " << j2.salary << " " << j2.floor << endl;
    double s;
    s = j1.salary;
    j1.salary = j2.salary;
    j2.salary = s;
    cout << "after change job:\n";
    cout << "j1: " << j1.name << " " << j1.salary << " " << j1.floor << endl;
    cout << "j2: " << j2.name << " " << j2.salary << " " << j2.floor << endl;
}

void show_array(const int a[], int n)
{
    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        cout << a[i];
        if (i < n - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

template<class T>
T Add(T a, T b)
{
    return a + b;
}

