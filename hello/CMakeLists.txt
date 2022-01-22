cmake_minimum_required(VERSION 3.18)

project(Hello CXX)

find_package(SDL2 REQUIRED)

add_executable(hello
 assets.cc
 es2ld.cc
 licenses.cc
 main.cc
 renderer.cc
 shell.cc
)
target_include_directories(hello
 PRIVATE
  ${SDL2_INCLUDE_DIRS}
)
target_link_options(hello
 PRIVATE
  -static-libgcc
  -static-libstdc++
)
target_link_libraries(hello
 PRIVATE
  ${SDL2_LIBRARIES}
)
