cmake_minimum_required(VERSION 3.10)
project(1c)

set(CMAKE_CXX_STANDARD 14)

include_directories(Trie)
include_directories(Solve)

add_executable(
        1c
        main.cpp
        Trie/Trie.cpp
        Solve/Solve.cpp
)
