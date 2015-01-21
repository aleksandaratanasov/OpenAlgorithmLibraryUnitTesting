project(GoogleCppTestFramework_TemplateProject)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -O3 -g0")
    #-O3 (level of optimization 3)
    #-g0 (no debug information)
    #disable all output by commenting out #define OUTPUT
endif()

# Locate GTest
link_directories(/usr/lib/gtest/)         # Add folder where the .so/.dll files are located
include_directories(/usr/include/gtest)   # Add folder where the include files are located
set(headers
  equalArrays.h
)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${headers} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} gtest gtest_main) # Link the library (e.g. libgtest_main.so on Linux)

