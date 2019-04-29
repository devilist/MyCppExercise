//
// Created by admin on 2019/4/26.
//
#include <vector>
#include <iostream>
#include "h/prime_chapter3.h"

using namespace std;

void vectorExercise();

void arrayExercise();


void exercise3() {
    arrayExercise();
    vectorExercise();
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
    for (unsigned i:v) {
        cout << i << " ";
    }

    vector<string> sv{"some", "days"};
    vector<string>::iterator sv_it = sv.begin();
}
