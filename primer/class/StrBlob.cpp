//
// Created by admin on 2019/5/8.
//

#include <iostream>
#include "StrBlob.h"

using namespace std;

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {

}

StrBlob::StrBlob(std::initializer_list<std::string> il)
        : data(make_shared<vector<string>>(il)) {

}

void StrBlob::pop_back() {
    data->pop_back();
}

std::string &StrBlob::front() {
    return data->front();
}

std::string &StrBlob::back() {
    return data->back();
}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        cout << "out of bound!" << endl;
    }
}
