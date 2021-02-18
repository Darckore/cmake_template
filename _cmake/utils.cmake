# Collect suitable source and header files inside the specified dir
function(collect_sources ROOT_DIR SOURCE_FILES)
  file( GLOB_RECURSE SRC
      LIST_DIRECTORIES false
      "${ROOT_DIR}/src/*.cpp*"
      "${ROOT_DIR}/include/*.h*"
      "${ROOT_DIR}/src/*/*.cpp*"
      "${ROOT_DIR}/include/*/*.h*" )
      
  set(SOURCE_FILES "${SRC}" PARENT_SCOPE)
endfunction()

# Group items according to their locations and purpose (for IDEs)
function(make_src_groups ROOT_DIR SOURCE_FILES)
  set(PCH_FILTER pch)
  source_group(TREE ${ROOT_DIR} FILES ${SOURCE_FILES})
  source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX ${PCH_FILTER} FILES ${OPT_PCH_NAME})
  
  file( GLOB_RECURSE GENERATED_PCH_FILES 
        LIST_DIRECTORIES false
        "${CMAKE_CURRENT_BINARY_DIR}/*pch.c*"
        "${CMAKE_CURRENT_BINARY_DIR}/*pch.h*")
  source_group(TREE ${CMAKE_CURRENT_BINARY_DIR} PREFIX ${PCH_FILTER} FILES ${GENERATED_PCH_FILES})
endfunction()

# Warning level
function(set_warn_level TARGET_NAME)
  if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
  else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
  endif()
endfunction()