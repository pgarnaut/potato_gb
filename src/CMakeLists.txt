# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.

include_directories(${Potato_SOURCE_DIR}/include)
link_libraries(stdc++fs)
file(GLOB SOURCES "*.cpp")

set(CMAKE_BINARY_DIR "bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Werror -Wno-unused -std=c++1z")
#set(CMAKE_CXX_LINK_FLAGS    "-lc++experimental")
set (CMAKE_CXX_STANDARD 17)

add_executable(potato_gb ${SOURCES})

