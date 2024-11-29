# Arkanoid Game

## Description
This is a simple Arkanoid game implemented using OpenGL, GLUT, and GLFW.

## Dependencies
To build and run this application, you need to have the following dependencies installed:

- CMake (version 3.10 or higher)
- OpenGL
- GLUT
- GLFW

## Installation

### macOS
1. Install Homebrew if you haven't already:
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

2. Install the required dependencies:
    ```sh
    brew install cmake
    brew install freeglut
    brew install glfw
    ```

## Building the Application
1. Clone the repository:
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```

4. Build the project:
    ```sh
    make
    ```

## Running the Application
After building the project, you can run the application with the following command:
```sh
./ArkanoidGame