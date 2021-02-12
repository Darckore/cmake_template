cmake_minimum_required(VERSION 3.18)

project(someproj CXX)

include("init.cmake")

enable_testing()

add_subdirectory("app")
add_subdirectory("libsomething")
add_subdirectory("test")

target_link_libraries(app libsomething)
target_link_libraries(tests libsomething)