cmake_minimum_required(VERSION 3.25)
project(datastruct)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(datastruct
        linearList.h
        main.cpp linearList.cpp )

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(datastruct PRIVATE -O0)
endif()