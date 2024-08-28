cmake_minimum_required(VERSION 3.16)

project(calc_core VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES calculator.h converter.h calculator.cpp converter.cpp)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)


add_library(calc_core STATIC ${SOURCE_FILES})

target_link_libraries(calc_core PRIVATE Qt6::Core)
