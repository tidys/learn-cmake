project(demo_lib)
aux_source_directory(./ SRC)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/debug)
add_library(lib ${SRC})