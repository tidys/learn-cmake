set(DLL_NAME "dll")
# 设置输出目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE dll_src ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(${DLL_NAME} SHARED ${dll_src})

source_group("src" FILES ${dll_src})
# target_sources(${LIB_NAME} PRIVATE ${SRC})

# 要放在add_library后边
target_include_directories(${DLL_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/)