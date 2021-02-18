cmake_minimum_required(VERSION 3.18)

include("${OPT_UTILS_DIR}/utils.cmake")
set(TARGET_NAME libsomething)

project(${TARGET_NAME} CXX)

set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
collect_sources(${SRC_ROOT} SOURCE_FILES)

add_library(${TARGET_NAME} STATIC ${SOURCE_FILES} ${OPT_PCH_NAME})

target_compile_features(${TARGET_NAME} PRIVATE ${OPT_CXX_STD})
target_precompile_headers(${TARGET_NAME} PRIVATE ${OPT_PCH_NAME})
target_include_directories(${TARGET_NAME} PUBLIC "${SRC_ROOT}/include")

make_src_groups(${SRC_ROOT} "${SOURCE_FILES}")

set_warn_level(${TARGET_NAME})