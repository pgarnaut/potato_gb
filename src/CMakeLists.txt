# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.

include_directories(${Potato_SOURCE_DIR}/include)
file(GLOB SOURCES "*.cpp")

set(CMAKE_BINARY_DIR "bin")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(potato_gb ${SOURCES})
