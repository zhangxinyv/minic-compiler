cmake_minimum_required(VERSION 3.19)
project(minic C)

set(CMAKE_C_STANDARD 99)

add_executable(minic main.c ast.h ir.h table.h ast.c ir.c table.c)