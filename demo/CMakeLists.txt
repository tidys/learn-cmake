cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/debug)
# 增加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/../lib)

aux_source_directory(./ SRCS)
add_executable(demo ${SRCS})
# 将lib链接到程序
target_link_libraries(demo lib) 
 
