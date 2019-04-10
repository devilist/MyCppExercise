# cmake_minimum_required(VERSION <specify CMake version here>)
project(MyCppExercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyCppExercise main.cpp
        exercise/chapter4.cpp exercise/h/chapter4.h
        exercise/chapter5.cpp exercise/h/chapter5.h
        exercise/chapter6.cpp exercise/h/chapter6.h
        exercise/chapter7.cpp exercise/h/chapter7.h
        exercise/chapter8.cpp exercise/h/chapter8.h
        exercise/chapter9.cpp exercise/h/chapter9.h
        exercise/class/stock.cpp exercise/class/stock.h
        exercise/chapter10.cpp exercise/h/chapter10.h
        exercise/class/stack.cpp exercise/class/stack.h
        exercise/class/stringwrapper.cpp exercise/class/stringwrapper.h
        exercise/class/queue.cpp exercise/class/queue.h
        exercise/chapter12.cpp exercise/h/chapter12.h
        exercise/class/acctabc.cpp exercise/class/acctabc.h
        exercise/class/student.cpp exercise/class/student.h
        exercise/class/stacktp.cpp exercise/class/stacktp.h
        exercise/chapter14.cpp exercise/h/chapter14.h
        primer/PrimerExercise.cpp primer/PrimerExercise.h
        exercise/PlusExercise.cpp exercise/PlusExercise.h)