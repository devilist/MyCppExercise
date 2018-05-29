//
// Created by zengp on 2018/1/27.
//

#ifndef MYCPPEXERCISE_STACK_H
#define MYCPPEXERCISE_STACK_H

typedef unsigned long Item; // 别名

class stack
{
private:

    enum
    {
        MAX = 10
    };

    Item items[MAX];
    int top;

public:
    stack();

    bool isempty() const;

    bool isfull() const;

    bool push(const Item &item);

    bool pop(Item &item);
};

#endif //MYCPPEXERCISE_STACK_H
