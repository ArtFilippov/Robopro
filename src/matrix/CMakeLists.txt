cmake_minimum_required(VERSION 3.5)

project(Matrix)

set(MATRIX_SRC matrix.c matrix.h)

add_library(Matrix STATIC ${MATRIX_SRC})