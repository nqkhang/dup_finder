cmake_minimum_required(VERSION 3.15)

project(dup_finder)

set(CMAKE_CXX_STANDARD 17)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/main.cpp src/my_node.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

#find_package(Threads)
find_package(OpenSSL REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(dup_finder ${SOURCES})

target_compile_features(dup_finder PRIVATE cxx_std_17)
#target_link_libraries(dup_finder PRIVATE Threads::Threads)
target_link_libraries(dup_finder PRIVATE openssl::openssl)
# target_link_libraries(dup_finder)