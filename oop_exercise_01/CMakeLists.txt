cmake_minimum_required(VERSION 3.5)

project(oop_exercise)

add_executable(oop_exercise_01 main.cpp)
set_target_properties(oop_exercise_01 PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )