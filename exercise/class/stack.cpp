//
// Created by zengp on 2018/1/27.
// 栈
//

#include "stack.h"


stack::stack()
{
    top = 0;
}

bool stack::isempty() const
{
    return top == 0;
}

bool stack::isfull() const
{
    return top == MAX;
}

bool stack::push(const Item &item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }

    return false;
}

bool stack::pop(Item &item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }

    return false;
}

