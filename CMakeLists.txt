# cmake_minimum_required(VERSION <specify CMake version here>)
project(MyCppExercise)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-std=c++11)

add_definitions(-D DEBUG=1)

SET(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall")

# 设置版本号
set(MyCppExercise_VERSION_MAJOR 1)
set(MyCppExercise_VERSION_MINOR 0)

set(CMAKE_CXX_FLAGS -std=c++11)             # c++11
set(CMAKE_CXX_FLAGS -g)                     # 调试信息
#set(CMAKE_CXX_FLAGS "-Wall")                  # 开启所有警告

aux_source_directory(${PROJECT_SOURCE_DIR}/exercise SRC_PRIMER_PLUS)
aux_source_directory(${PROJECT_SOURCE_DIR}/exercise/class SRC_PRIMER_PLUS)
include_directories(${PROJECT_SOURCE_DIR}/exercise)
add_executable(PrimerPlus exercise_main.cpp ${SRC_PRIMER_PLUS})

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/primer SRC_PRIMER)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/primer/class SRC_PRIMER)
include_directories(${CMAKE_CURRENT_LIST_DIR}/primer)
add_executable(Primer primer_main.cpp ${SRC_PRIMER} primer/class/StrBlob.cpp primer/class/StrBlob.h primer/class/StrBlobPtr.cpp primer/class/StrBlobPtr.h)