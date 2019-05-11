//
// Created by admin on 2019/5/11.
//

#include "TBlob.h"


template<typename T>
TBlob<T>::TBlob():data(std::make_shared<std::vector<T>>()) {

}

template<typename T>
TBlob<T>::TBlob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)) {

}

template<typename T>
void TBlob<T>::pop_back() {
    check(0, "pop back");
    data->pop_back();
}

template<typename T>
T &TBlob<T>::back() {
    check(0, "back on empty Tblob");
    return data->back();
}

template<typename T>
T &TBlob<T>::operator[](TBlob::size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
void TBlob<T>::check(TBlob::size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
