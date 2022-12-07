cmake_minimum_required(VERSION 3.0)

project(AoC2022)

# find packages
# find_package(Eigen3)

# includes
include_directories(
  utils/include
)

add_executable(${PROJECT_NAME}_day1 day1/day1.cpp)
target_compile_options(${PROJECT_NAME}_day1 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day2 day2/day2.cpp)
target_compile_options(${PROJECT_NAME}_day2 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day3 day3/day3.cpp)
target_compile_options(${PROJECT_NAME}_day3 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day4 day4/day4.cpp)
target_compile_options(${PROJECT_NAME}_day4 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day5 day5/day5.cpp)
target_compile_options(${PROJECT_NAME}_day5 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day6 day6/day6.cpp)
target_compile_options(${PROJECT_NAME}_day6 PUBLIC -std=c++20 -O3)