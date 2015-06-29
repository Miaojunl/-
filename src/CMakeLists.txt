cmake_minimum_required(VERSION 2.6)

project(sort)

include_directories(allsort headsort mysort selectsor bubblesort qsort)
add_subdirectory (../src bin)

add_executable(sort main.cpp)
target_link_libraries (sort allsort headsort mysort selectsort bubblesort qsort)


