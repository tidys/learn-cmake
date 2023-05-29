cmake_minimum_required(VERSION 3.0.0)
set(app "lear-cmake")
project(${app} VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0111 OLD)

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 增加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/lib)
add_compile_definitions(TEST=0)

include(./lib/CMakeLists.txt)

# include(./dll/CMakeLists.txt) # 项目内的dll
include(./prebuilt/CMakeLists.txt) # 项目外的dll

# GLOB_RECURSE 会遍历子目录
file(GLOB app_src
    ${CMAKE_CURRENT_LIST_DIR}/*.h
    ${CMAKE_CURRENT_LIST_DIR}/prebuilt/*.h
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(${app} ${app_src})

# 将lib链接到程序
target_link_libraries(${app} PRIVATE lib dll)

# 使用自定义文件夹，将lib放到3rd文件分组下
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(
    lib dll
    PROPERTIES
    FOLDER "3rd"
)

source_group("src" FILES ${app_src})
