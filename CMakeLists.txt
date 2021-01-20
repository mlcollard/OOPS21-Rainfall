# @file CMakeLists.txt
# 
# CMake files for the rainfall program

cmake_minimum_required(VERSION 3.10)

# project info
project(Rainfall)

# C++17
set(CMAKE_CXX_STANDARD 17)

# Turn on warnings
if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # standard warnings
    add_compile_options(-Wall)
endif()

# Rainfall program
add_executable(rainfall rainfall.cpp)

# run command
add_custom_target(run $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/rainfall.csv)

# check command
add_custom_target(check 
    COMMAND $<TARGET_FILE:rainfall> < ${CMAKE_SOURCE_DIR}/rainfall.csv > testrun.txt
    COMMAND diff ${CMAKE_SOURCE_DIR}/report.txt testrun.txt
    COMMAND ${CMAKE_COMMAND} -E rm -f testrun.txt
)
