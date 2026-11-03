cmake_minimum_required(VERSION 3.10)
project(hello_c_gnulib C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${CMAKE_CURRENT_SOURCE_DIR} -I${CMAKE_CURRENT_BINARY_DIR}")
find_file(CONFIG_H "config.h" PATHS ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} NO_CACHE)

if(CONFIG_H)
    file(GLOB GNULIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.c")
    
    if(NOT GNULIB_SOURCES)
        message(WARNING "Gnulib sources not found. Run autogen.sh first.")
    endif()
    
    add_executable(hello hello.c)
    
    if(GNULIB_SOURCES)
        add_library(gnulib STATIC ${GNULIB_SOURCES})
        target_include_directories(gnulib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/lib ${CMAKE_CURRENT_BINARY_DIR})
        target_link_libraries(hello PRIVATE gnulib)
    endif()
else()
    message(FATAL_ERROR "config.h not found. Run autogen.sh first to generate gnulib files, or use hello-c-nognulib example.")
endif()
