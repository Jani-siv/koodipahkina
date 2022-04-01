#cmake version
cmake_minimum_required(VERSION 3.16.0)
#cmake project
project(Koodipahkina VERSION 0.01)
#C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DMY_DEBUG")
#include dir
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
#flags
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#make executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
