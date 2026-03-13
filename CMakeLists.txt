cmake_minimum_required(VERSION 3.15)
project(gnulib_examples C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(hello-c-gnulib)
add_subdirectory(hello-c-gnulib-automakesubdir)
add_subdirectory(hello-c-gnulib-automakesubdir-withtests)
add_subdirectory(hello-c-gnulib-conddeps)
add_subdirectory(hello-c-gnulib-nonrecursive)
add_subdirectory(hello-c-nognulib)
