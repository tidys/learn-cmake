set(LIB_NAME "lib")
project(${LIB_NAME})
add_library(${LIB_NAME})

# 设置输出目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

aux_source_directory(./ SRC)
target_sources(${LIB_NAME} PRIVATE ${SRC})

# 要放在add_library后边
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)