cmake_minimum_required(VERSION 3.18)
include(ExternalProject)

set(FMT_DL "fmt-download")
configure_file(CMakeLists.txt.in "${CMAKE_BINARY_DIR}/${FMT_DL}/CMakeLists.txt")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
               WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${FMT_DL}")
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${FMT_DL}")

add_subdirectory("${OPT_FMT_DIR}"
                 "${CMAKE_BINARY_DIR}/fmt-build")