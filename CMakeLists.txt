cmake_minimum_required(VERSION 3.28)
project(CDataStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(
        include
)

add_library(CDataStructure STATIC
        include/list.h
        src/list.c)
