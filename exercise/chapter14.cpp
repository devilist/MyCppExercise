//
// Created by zengp on 2018/2/5.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <cctype>
#include "h/chapter14.h"
#include "class/stacktp.h"

using std::cout;
using std::cin;
void testStackTP();

void exercise14()
{
    testStackTP();

}

void testStackTP()
{
    StackTP<std::string> st;
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order.\n"
         << "P to process a Po, or Q to quit.\n";
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            cout << 'a';
            continue;
        }

        switch (ch)
        {
            case 'A':
            case 'a':cout << "Enter a PO number to add: ";
                cin >> po;
                if (st.isfull())
                    cout << "stack already full \n";
                else st.push(po);
                break;
            case 'P':
            case 'p':
                if (st.isempty())
            cout << "stack already empty\n";
        else
            st.pop(po);
                cout << "PO #" << po << " popped\n";
                break;
        }
        cout << "Please enter A to add a purchase order.\n"
             << "P to process a Po, or Q to quit.\n";
    }
    cout << "bye \n";
};