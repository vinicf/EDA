cmake_minimum_required(VERSION 3.21)
project(EDA C)

set(CMAKE_C_STANDARD 99)

add_executable(EDA main.c grafo_matriz_adjacencia.c grafo_matriz_adjacencia.h)