cmake_minimum_required(VERSION 3.18)

project(someproj CXX)

include("init.cmake")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)


add_subdirectory("libsomething")

if(OPT_APP)
  add_subdirectory("app")
  target_link_libraries(app libsomething)
endif()

if(OPT_TESTS)
  enable_testing()
  add_subdirectory("test")
  target_link_libraries(tests libsomething)
  add_dependencies(tests app)
endif()