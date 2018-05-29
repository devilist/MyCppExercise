//
// Created by zengp on 2018/2/5.
//

#ifndef MYCPPEXERCISE_STACKTP_H
#define MYCPPEXERCISE_STACKTP_H

template<class T>
class StackTP
{
private:
    enum
    {
        MAX = 10
    };

    T items[MAX];

    int top;

public:
    StackTP();

    bool isempty();

    bool isfull();

    bool push(const T &item);

    bool pop(T &item);
};

//--------------------------------------------
template<class T>
StackTP<T>::StackTP()
{
    top = 0;
}

template<class T>
bool StackTP<T>::isempty()
{
    return top == 0;
}

template<class T>
bool StackTP<T>::isfull()
{
    return top == MAX;
}

template<class T>
bool StackTP<T>::push(const T &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    return false;
}

template<class T>
bool StackTP<T>::pop(T &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    return false;
}

#endif //MYCPPEXERCISE_STACKTP_H
