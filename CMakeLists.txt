cmake_minimum_required(VERSION 2.6)
project(bin_game2)

file(GLOB sources "src/*/*.cpp", "src/*.cpp")

include_directories(src/console)
include_directories(src/controller)
include_directories(src/model)
include_directories(src/view)
include_directories(src)

add_executable(bin_game2 ${sources})
