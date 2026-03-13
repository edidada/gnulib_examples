cmake_minimum_required(VERSION 3.10)
project(hello_c_gnulib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_SOURCE_DIR} -I${CMAKE_BINARY_DIR}")

file(GLOB GNULIB_SOURCES "${CMAKE_SOURCE_DIR}/lib/*.c")
file(GLOB GNULIB_HEADERS "${CMAKE_SOURCE_DIR}/lib/*.h")

if(NOT GNULIB_SOURCES)
    message(WARNING "Gnulib sources not found. Run autogen.sh first to generate gnulib files.")
endif()

add_executable(hello-c-gnulib hello.c)

if(GNULIB_SOURCES)
    add_library(gnulib STATIC ${GNULIB_SOURCES})
    target_include_directories(gnulib PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
    target_link_libraries(hello PRIVATE gnulib)
endif()
