cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
message(${Python3_INCLUDE_DIRS})

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# 增加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/lib)
add_compile_definitions(TEST=0)

include(./lib/CMakeLists.txt)

# GLOB_RECURSE 会遍历子目录
file(GLOB demo_src ${CMAKE_CURRENT_LIST_DIR}/*.h ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_executable(demo   ${demo_src})

# 将lib链接到程序
target_link_libraries(demo lib) 
 

# 使用自定义文件夹，将lib放到3rd文件分组下
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_target_properties(
    lib
    PROPERTIES
        FOLDER "3rd"
)

source_group("src" FILES ${demo_src})
