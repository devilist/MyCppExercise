//
// Created by admin on 2019/4/10.
//

#include "h/prime_chapter3.h"
#include "h/prime_chapter6.h"
#include "h/prime_chapter13.h"
#include "h/prime_chapter15.h"
#include "PrimerExercise.h"

void runExercise(int chapter);

void runPrimeExercise() {
    int chapter = 13;
    runExercise(chapter);
};

void runExercise(int chapter) {
    switch (chapter) {
        case 3:
            exercise3();
            break;
        case 6:
            exercise_6();
            break;
        case 13:
            exercise_13();
            break;
        default:
            break;
    }

}