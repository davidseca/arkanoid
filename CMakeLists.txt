cmake_minimum_required(VERSION 3.10)
project(ArkanoidGame)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(glfw3 3.3 REQUIRED)

add_executable(ArkanoidGame
               Sources/Ball.cpp
               Sources/Ball.h
               Sources/Brick.cpp
               Sources/Brick.h
               Sources/Paddle.cpp
               Sources/Paddle.h
               Sources/Wall.cpp
               Sources/Wall.h
               Sources/FileUtils.cpp
               Sources/FileUtils.h
               Sources/Level.h
               Sources/LevelConfig.h
               Sources/Mapper.cpp
               Sources/Mapper.h
               Sources/main.cpp)

target_link_libraries(ArkanoidGame
    PUBLIC
        OpenGL::GL
        GLUT::GLUT
        glfw
)
add_executable(Sources_main Sources/main.cpp)