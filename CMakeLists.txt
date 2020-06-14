cmake_minimum_required(VERSION 3.16)
project(cv-test)

# Setup the environment.
set(CMAKE_CXX_STANDARD 14)
message("CMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}")

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})