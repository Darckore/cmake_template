cmake_minimum_required(VERSION 3.18)

project(someproj CXX)

include("init.cmake")

add_subdirectory("app")
add_subdirectory("libsomething")

target_link_libraries(app libsomething)