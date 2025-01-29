cmake_minimum_required(VERSION 3.10)
project(Exercises)

set(CMAKE_CXX_STANDARD 17)

if(NOT DEFINED NUM)
    message(FATAL_ERROR "Please specify NUM, e.g., cmake -DNUM=1 ..")
endif()

set(SOURCE_FILE "src/${NUM}.*.cpp")
file(GLOB FILES ${SOURCE_FILE})

message(STATUS ${FILES})

list(GET FILES 0 SELECTED_FILE)

if(NOT SELECTED_FILE)
    message(FATAL_ERROR "No matching file found for NUM=${NUM}")
endif()

add_executable(out ${SELECTED_FILE})
