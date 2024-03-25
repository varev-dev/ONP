cmake_minimum_required(VERSION 3.26)
project(ONPinC C)

set(CMAKE_C_STANDARD 17)

add_executable(ONPinC main.c
        includes/Token.h
        sources/Token.c
        includes/Node.h
        includes/Stack.h
        sources/Node.c
        sources/Stack.c
        includes/Reader.h
        sources/Reader.c
        includes/Calculator.h
        sources/Calculator.c
)
