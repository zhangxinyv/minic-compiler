cmake_minimum_required(VERSION 3.19)
project(minic C)

set(CMAKE_C_STANDARD 99)

add_executable(minic
        main.c
        ast.c
        ast.h
        ir.h
        ir.c
        table.h
        table.c
        minic_lex.c
        minic_lex.h
        minic_yacc.c
        minic_yacc.h
        util.c util.h)