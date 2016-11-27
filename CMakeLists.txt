cmake_minimum_required(VERSION 3.6)
project(Huffman)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c tools.c arbre.c arbre.h tools.h)
add_executable(Huffman ${SOURCE_FILES})