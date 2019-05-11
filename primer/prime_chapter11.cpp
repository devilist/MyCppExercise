//
// Created by ZengPu on 2019-05-08.
//


#include <iostream>
#include <algorithm>

// 关联容器
#include <map>
#include <hash_map>
#include <unordered_map>
#include <set>
#include <hash_set>
#include <unordered_set>

// 顺序容器
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>

// 容器适配器
#include <stack>
#include <queue>

#include "h/prime_chapter11.h"

using namespace std;

void mapRun();

void algorithmRun();

void exercise_11() {
    mapRun();
    algorithmRun();
}

void mapRun() {
    map<string, int> m_Map;
    multimap<string, int> m_MultiMap;
    unordered_map<string, int> m_UnMap;
    unordered_multimap<string, int> m_UnMultiMap;

    set<string> m_Set;
    multiset<string> m_MultiSet;
    unordered_set<string> m_UnSet;
    unordered_multiset<string> m_UnMultiSet;

    // 栈适配器
    stack<int> intStack;
    for (int i = 0; i < 10; ++i) {
        intStack.push(i);
    }
    while (!intStack.empty()) {
        int val = intStack.top();
        cout << val;
        intStack.pop();
    }
    cout << endl;

    // 队列适配器  fifo
    queue<int> intQueue;
}

void algorithmRun() {
//    find()
}


