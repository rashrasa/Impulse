add_library(vec2 vec2.cpp ${HEADER_SET})

target_include_directories(vec2 PUBLIC ../include)

target_compile_features(vec2 PUBLIC cxx_std_23)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
