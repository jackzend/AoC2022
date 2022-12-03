cmake_minimum_required(VERSION 3.0)

project(AoC2022)

# find packages
# find_package(Eigen3)

# includes
include_directories(
  utils/include
)

add_executable(${PROJECT_NAME}_day1 day1/day1.cpp)
target_compile_options(${PROJECT_NAME}_day1 PUBLIC -std=c++2a -O3)

add_executable(${PROJECT_NAME}_day2 day2/day2.cpp)
target_compile_options(${PROJECT_NAME}_day2 PUBLIC -std=c++2a -O3)