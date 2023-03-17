cmake_minimum_required(VERSION 3.10)


set(DLL_NAME "dll")
project(${DLL_NAME} )
# LANGUAGE CXX
# 设置输出目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE dll_src 
    ${CMAKE_CURRENT_LIST_DIR}/dll.h
    ${CMAKE_CURRENT_LIST_DIR}/dll.cpp
)

add_library(${DLL_NAME} SHARED ${dll_src})

source_group("src" FILES ${dll_src})
# target_sources(${LIB_NAME} PRIVATE ${SRC})

# 要放在add_library后边
target_include_directories(${DLL_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/)