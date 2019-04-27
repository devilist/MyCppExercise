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
    vectorExercise();

}

void arrayExercise() {
    unsigned size = 10;
    int int_array[size];
    string bad[size];
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
