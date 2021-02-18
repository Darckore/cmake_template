cmake_minimum_required(VERSION 3.18)

set(OPT_PCH_NAME "pch.h")
set(OPT_CXX_STD "cxx_std_20")
set(OPT_UTILS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/_cmake")
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

if (NOT DEFINED BUILT_FROM_ROOT)
  set(BUILT_FROM_ROOT OFF)
  if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    set(BUILT_FROM_ROOT ON)
  endif ()
endif ()

set(OPT_FMT_DIR "${CMAKE_SOURCE_DIR}/../_third_party/fmtlib" CACHE PATH "Fmtlib repo will be cloned here")
option(OPT_FMT "Whether or not to build the fmt lib" ON)

set(OPT_GTEST_DIR "${CMAKE_SOURCE_DIR}/../_third_party/gtest" CACHE PATH "Gtest repo will be cloned here")
option(OPT_TESTS "Whether or not to build tests" ${BUILT_FROM_ROOT})

option(OPT_APP "Whether or not to build the application" ${BUILT_FROM_ROOT})

project(someproj CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(THIRD_PARTY_DIR third_party)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER cmake)

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
  
  if(OPT_APP)
    add_dependencies(tests app)
  endif()
  
  set_target_properties(gtest PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gmock PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gtest_main PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  set_target_properties(gmock_main PROPERTIES FOLDER ${THIRD_PARTY_DIR}/gtest)
  
  target_compile_definitions(tests PUBLIC GTEST_BUILT)
endif()

if(OPT_FMT)
  add_subdirectory("${OPT_UTILS_DIR}/third_party/fmt" fmt)
  target_link_libraries(libsomething fmt)
  set_target_properties(fmt PROPERTIES FOLDER ${THIRD_PARTY_DIR}/fmt)
  
  target_compile_definitions(libsomething PUBLIC FMT_BUILT)
endif()