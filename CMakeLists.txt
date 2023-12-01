cmake_minimum_required(VERSION 3.5)
project(Test)
add_executable(test main.cpp)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
target_compile_definitions(test PUBLIC "LINUX_OS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
target_compile_definitions(test PUBLIC "WINDOWS_OS")
endif()
set_target_properties(
    test PROPERTIES 
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
