//
// Created by admin on 2019/5/11.
//

#ifndef MYCPPEXERCISE_TBLOB_H
#define MYCPPEXERCISE_TBLOB_H

#include <iostream>
#include <memory>
#include <vector>

template<typename T>
class TBlobPtr;

template<typename T>
class TBlob;

template<typename T>
bool operator==(const TBlob<T> &, const TBlob<T> &);

template<typename T>
class TBlob {

    friend class TBlobPtr<T>;

    friend bool operator==<T>(const TBlob<T> &, const TBlob<T> &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    TBlob();

    TBlob(std::initializer_list<T> il);

    size_type size() const { return data->size(); }

    bool empty() const { return data->empty(); }

    void push_back(const T &t) { data->push_back(t); }

    void pop_back();

    T &back();

    T &operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type i, const std::string &msg) const;
};


#endif //MYCPPEXERCISE_TBLOB_H
