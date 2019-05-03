//
// Created by admin on 2019/4/10.
//

#include "h/prime_chapter3.h"
#include "h/prime_chapter6.h"
#include "PrimerExercise.h"

void runExercise(int chapter);

void runPrimeExercise() {
    int chapter = 6;
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
        default:
            break;
    }

}