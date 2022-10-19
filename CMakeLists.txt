cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
include(CTest)
enable_testing()

add_subdirectory(./lib)
aux_source_directory(./ SRCS)
add_executable(demo ${SRCS})
target_link_libraries(demo lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack) 
