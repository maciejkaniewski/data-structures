cmake_minimum_required(VERSION 3.0)
project(Data_Structures) 

execute_process(
        COMMAND git clone "https://github.com/google/googletest.git" googletest
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

add_subdirectory(googletest) 
include_directories(googletest/include inc) 
add_executable(Test_Data_Structures src/test_data_structures.cpp) 
target_link_libraries(Test_Data_Structures PRIVATE gtest)
