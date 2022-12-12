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

add_executable(${PROJECT_NAME}_day7 day7/day7.cpp)
target_compile_options(${PROJECT_NAME}_day7 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day8 day8/day8.cpp)
target_compile_options(${PROJECT_NAME}_day8 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day9 day9/day9.cpp)
target_compile_options(${PROJECT_NAME}_day9 PUBLIC -std=c++20 -O3 -Ofast)

add_executable(${PROJECT_NAME}_day10 day10/day10.cpp)
target_compile_options(${PROJECT_NAME}_day10 PUBLIC -std=c++20 -O3)

add_executable(${PROJECT_NAME}_day11 day11/day11.cpp)
target_compile_options(${PROJECT_NAME}_day11 PUBLIC -std=c++20 -O3 -Ofast)

add_executable(${PROJECT_NAME}_day12 day12/day12.cpp)
target_compile_options(${PROJECT_NAME}_day12 PUBLIC -std=c++20 -O3 -Ofast)