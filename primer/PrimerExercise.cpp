//
// Created by admin on 2019/4/10.
//

#include "h/prime_chapter3.h"
#include "PrimerExercise.h"

void runExercise(int chapter);

void runPrimeExercise() {
    int chapter = 3;
    runExercise(chapter);
};

void runExercise(int chapter) {
    switch (chapter) {
        case 3:
            exercise3();
            break;
        default:
            break;
    }

}