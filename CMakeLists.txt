cmake_minimum_required(VERSION 3.6)
project(Huffman)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c tools.c arbre.c arbre.h tools.h)
add_executable(Huffman ${SOURCE_FILES})