cmake_minimum_required(VERSION 3.10)
project(ArkanoidGame)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(ArkanoidGame
               Sources/Ball.cpp
               Sources/Ball.h
               Sources/Brick.cpp
               Sources/Brick.h
               Sources/Paddle.cpp
               Sources/Paddle.h
               Sources/main.cpp)

target_link_libraries(ArkanoidGame OpenGL::GL glfw)