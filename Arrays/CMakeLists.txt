cmake_minimum_required(VERSION 3.25)
project(Arrays C)

set(CMAKE_C_STANDARD 11)

add_executable(Arrays src/Arrays.c src/basics.c src/strings.c)
