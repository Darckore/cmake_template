cmake_minimum_required(VERSION 3.18)
find_package(Threads REQUIRED)

include(ExternalProject)

set(GTEST_DL "googletest-download")
configure_file(CMakeLists.txt.in "${CMAKE_BINARY_DIR}/${GTEST_DL}/CMakeLists.txt")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
               WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${GTEST_DL}")
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
                WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/${GTEST_DL}")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")


#####################################################################

include("${OPT_UTILS_DIR}/utils.cmake")
set(TARGET_NAME tests)

include(GoogleTest)

project(${TARGET_NAME} CXX)

set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
collect_sources(${SRC_ROOT} SOURCE_FILES)

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${OPT_PCH_NAME})

target_compile_features(${TARGET_NAME} PRIVATE ${OPT_CXX_STD})
target_precompile_headers(${TARGET_NAME} PRIVATE ${OPT_PCH_NAME})
make_src_groups(${SRC_ROOT} "${SOURCE_FILES}")

set_warn_level(${TARGET_NAME})

target_link_libraries(${TARGET_NAME} gtest)
gtest_discover_tests(${TARGET_NAME})

if(MSVC)
  set_target_properties(
  ${TARGET_NAME} PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET_NAME}>")
endif()