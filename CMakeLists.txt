# cmake_minimum_required(VERSION 2.8.9)
project(dup_finder)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/my_node.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

#find_package(Threads)

add_executable(dup_finder ${SOURCES})

target_compile_features(dup_finder PRIVATE cxx_std_17)
#target_link_libraries(dup_finder PRIVATE Threads::Threads)
target_link_libraries(dup_finder)