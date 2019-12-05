//
// Created by admin on 2019/5/15.
//

#include <iostream>
#include "JsonParser.h"

int main() {
    parserJson();
    int *s = new int[4]{1,1,1,0};
    std::cout << s[3] << std::endl;
    return 0;
}