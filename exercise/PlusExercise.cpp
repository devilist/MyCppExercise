//
// Created by admin on 2019/4/10.
//
#include <iostream>
#include "PlusExercise.h"

void runPlusExercise(int chapter);

void runPlusExercise() {
    int chapter = 14;
    runPlusExercise(chapter);

}

void runPlusExercise(int chapter) {
    switch (chapter) {
        case 4:
            exercise4();
            break;
        case 5:
            exercise5();
            break;
        case 6:
            exercise6();
            break;
        case 7:
            exercise7();
            break;
        case 8:
            exercise8();
            break;
        case 9:
            exercise9();
            break;
        case 10:
            exercise10();
            break;
        case 12:
            exercise12();
            break;
        case 14:
            exercise14();
            break;
        default:
            break;
    }
}