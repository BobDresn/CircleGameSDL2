cmake_minimum_required(VERSION 3.15)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(MyProject PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(MyProject PRIVATE ${SDL2_LIBRARIES})