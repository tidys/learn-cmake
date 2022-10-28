set(LIB_NAME "lib")
# 设置输出目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE lib_src ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(${LIB_NAME} ${lib_src})

source_group("src" FILES ${lib_src})
# target_sources(${LIB_NAME} PRIVATE ${SRC})

# 要放在add_library后边
target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/)