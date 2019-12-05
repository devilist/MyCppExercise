//
// Created by admin on 2019/4/26.
//
#include <vector>
#include <iostream>
#include "h/prime_chapter3.h"

typedef struct {
    float x;
    float y;
} vec2;

float arrayF[]{1.0f, 2.0f, 3.0f, 4.0f};

using namespace std;

void vectorExercise();

void arrayExercise();

void fun_print_int_array(int arr[]);

void fun_print_array(int(&)[10]);

void pointTrans(vec2 *v);

void exercise3() {
    arrayExercise();
    vectorExercise();
    pointTrans((vec2 *) arrayF);
}

void arrayExercise() {
    const unsigned size = 10;
    int int_array[size] = {21, 0, 0};
    string bad[size];
    int *pStart = begin(int_array);
    int *pEnd = end(int_array);
    cout << "pStart " << *pStart << endl;
    cout << "pEnd " << *pEnd << endl;
///////////////////////////////////////////////////////
    int ia[3][4] = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };

    for (auto p = ia; p != ia + 3; p++) {
        for (auto q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    cout << "no use auto" << endl;
    for (int(*p)[4] = ia; p != ia + 3; p++) {
        // p是一个指向长度为4的数组的指针，对p解引用后得到该数组
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }
    cout << "use iter" << endl;
    for (int(*p)[4] = begin(ia); p != end(ia); p++) {
        for (int *q = begin(*p); q != end(*p); ++q) {
            cout << *q << ",";
        }
        cout << endl;
    }
    cout << endl;
    cout << "int array size :" << sizeof(int_array) / sizeof(int) << endl;
    fun_print_int_array(int_array);
    float fArray[3];
}

void vectorExercise() {
    vector<unsigned> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (unsigned &i:v) {
        i *= i;
    }
    v.insert(v.begin() + 2, 12);
    for (unsigned i:v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "vector size " << v.size() << endl;
    vector<unsigned>::iterator it = v.begin();
    cout << typeid(it).name() << endl;

    for (auto it = v.begin(); it != v.end(); it++) {
        *it = *it - 1;
    }
    it = v.begin();
    while (it != v.end()) {
        cout << *it++ << " ";
    }
    cout << endl;

    vector<string> sv{"some", "days"};
    vector<string>::iterator sv_it = sv.begin();
}

void fun_print_int_array(int arr[]) {
    cout << "fun_print_int_array size :" << sizeof(arr) << endl;
    cout << "fun_print_int_array size :" << arr << endl;
    cout << "fun_print_int_array size :" << &arr << endl;
    cout << "fun_print_int_array size :" << *arr << endl;

}

void fun_print_array(int (&iarr)[10]) {

    for (int i:iarr) {
        cout << i << endl;
    }

}

void pointTrans(vec2 *v) {
    cout << "x " << v[0].x << " y " << v[0].y << endl;
}
