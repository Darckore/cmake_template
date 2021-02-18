cmake_minimum_required(VERSION 3.18)

include("${OPT_UTILS_DIR}/utils.cmake")

project(${TARGET_NAME} CXX)

collect_sources(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_library(${TARGET_NAME} STATIC ${SOURCE_FILES} ${OPT_PCH_NAME})

target_compile_features(${TARGET_NAME} PRIVATE ${OPT_CXX_STD})
target_precompile_headers(${TARGET_NAME} PRIVATE ${OPT_PCH_NAME})
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

make_src_groups(${CMAKE_CURRENT_SOURCE_DIR} "${SOURCE_FILES}")

set_warn_level(${TARGET_NAME})