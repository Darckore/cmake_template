cmake_minimum_required(VERSION 3.18)

include("${OPT_UTILS_DIR}/utils.cmake")

include(GoogleTest)

project(${TARGET_NAME} CXX)

collect_sources(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_FILES)

add_executable(${TARGET_NAME} ${SOURCE_FILES} ${OPT_PCH_NAME})

target_compile_features(${TARGET_NAME} PRIVATE ${OPT_CXX_STD})
target_precompile_headers(${TARGET_NAME} PRIVATE ${OPT_PCH_NAME})
make_src_groups(${CMAKE_CURRENT_SOURCE_DIR} "${SOURCE_FILES}")

set_warn_level(${TARGET_NAME})

target_link_libraries(${TARGET_NAME} gtest gmock gtest_main gmock_main)
gtest_discover_tests(${TARGET_NAME})
add_compile_definitions(TEST_BASE_DIR="$<TARGET_FILE_DIR:${TARGET_NAME}>")

if(MSVC)
  set_target_properties(
    ${TARGET_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET_NAME}>"
    VS_DEBUGGER_COMMAND_ARGUMENTS "--gtest_filter=*")
endif()