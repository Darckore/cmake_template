cmake_minimum_required(VERSION 3.18)

include("${OPT_UTILS_DIR}/utils.cmake")
set(TARGET_NAME app)

project(${TARGET_NAME} CXX)

set(SRC_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
collect_sources(${SRC_ROOT} SOURCE_FILES)

set(ADDITIONAL_FILES "${CMAKE_CURRENT_SOURCE_DIR}/sample/some_test_file")

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${OPT_PCH_NAME} ${ADDITIONAL_FILES})

target_compile_features(${TARGET_NAME} PRIVATE ${OPT_CXX_STD})
target_precompile_headers(${TARGET_NAME} PRIVATE ${OPT_PCH_NAME})
make_src_groups(${SRC_ROOT} "${SOURCE_FILES}")

set_warn_level(${TARGET_NAME})

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   "${CMAKE_CURRENT_SOURCE_DIR}/sample"
                   "$<TARGET_FILE_DIR:${TARGET_NAME}>/sample")

source_group("sample" ${ADDITIONAL_FILES})

if(MSVC)
  set_target_properties(
  ${TARGET_NAME} PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET_NAME}>")
endif()