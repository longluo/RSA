cmake_minimum_required(VERSION 3.16)
project(RSA C)

set(CMAKE_C_STANDARD 11)

add_library(math STATIC main.c)

add_executable(RSA main.c)

target_link_libraries(RSA m)
