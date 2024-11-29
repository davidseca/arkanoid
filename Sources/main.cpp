#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Wall.h"
#include <cstdlib>
#include <GL/glut.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BALL_START_X 400
#define BALL_START_Y 300
#define PADDLE_START_X 350
#define PADDLE_START_Y 550
#define PADDLE_WIDTH 100
#define PADDLE_HEIGHT 20
#define PADDLE_SPEED 6.0f
#define WALL_THICKNESS 20
#define BRICK_ROWS 11
#define BRICK_COLS 6
#define BRICK_WIDTH 60
#define BRICK_HEIGHT 20
#define BRICK_START_X 50
#define BRICK_START_Y 50

void resetGame(Paddle &paddle, Ball &ball, std::vector<Brick> &bricks) {
    paddle.setX(PADDLE_START_X);
    paddle.setY(PADDLE_START_Y);
    ball.setX(BALL_START_X);
    ball.setY(BALL_START_Y);

    for (auto &brick : bricks) {
        brick.setDestroyed(false);
    }
 }

void renderScore(int score) {
    std::string scoreText = "Score: " + std::to_string(score);
    glColor3f(0.0f, 0.0f, 1.0f); // Set color to blue
    glRasterPos2f(WINDOW_WIDTH - 100, 20); // Position at the top right
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    glColor3f(1.0f, 1.0f, 1.0f); // Set color back to white
}

int main(int argc, char** argv) {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Arkanoid Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WINDOW_WIDTH, WINDOW_HEIGHT, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Paddle paddle(PADDLE_START_X, PADDLE_START_Y, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_SPEED);
    Ball ball(BALL_START_X, BALL_START_Y);
    int score = 0;
    std::vector<Brick> bricks;
    Wall topWall(0, 0, WINDOW_WIDTH, WALL_THICKNESS); // Wall at the top of the screen
    Wall leftWall(0, 0, WALL_THICKNESS, WINDOW_HEIGHT); // Wall on the left side of the screen
    Wall rightWall(WINDOW_WIDTH - WALL_THICKNESS, 0, WALL_THICKNESS, WINDOW_HEIGHT); // Wall on the right side of the screen

    // Create bricks
    for (int row = 0; row < BRICK_ROWS; ++row) {
        for (int col = 0; col < BRICK_COLS; ++col) {
            bricks.emplace_back(BRICK_WIDTH * row + BRICK_START_X + row * 5,
                                BRICK_HEIGHT * col + BRICK_START_Y + col * 5,
                                BRICK_WIDTH,
                                BRICK_HEIGHT);
        }
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Paddle movement
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS && paddle.getX() > leftWall.getWidth()) {
            paddle.move(-paddle.getSpeed());
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS && paddle.getX() + paddle.getWidth() < rightWall.getX()) {
            paddle.move(paddle.getSpeed());
        }

        // Ball movement
        ball.update();

        // Collision detection and response (simplified)
        if (ball.getX() + ball.getRadius() > paddle.getX() && ball.getX() - ball.getRadius() < paddle.getX() + paddle.getWidth() &&
            ball.getY() + ball.getRadius() > paddle.getY() && ball.getY() - ball.getRadius() < paddle.getY() + paddle.getHeight()) {
            ball.setDy(-ball.getDy());
        }

        // Collision detection and response (simplified)
        if (ball.getX() - ball.getRadius() < 0 || ball.getX() + ball.getRadius() > WINDOW_WIDTH) {
            ball.setDx(-ball.getDx());
        }

        if (ball.getY() - ball.getRadius() < topWall.getHeight()) {
            ball.setDy(-ball.getDy() + (rand() % 3 - 1) * 0.1f);
        } else if (ball.getY() + ball.getRadius() > WINDOW_HEIGHT) {
            resetGame(paddle, ball, bricks);
            score = 0;
        }

        for (auto& brick : bricks) {
            if (!brick.isDestroyed() && ball.getX() + ball.getRadius() > brick.getX() && ball.getX() - ball.getRadius() < brick.getX() + brick.getWidth() &&
                ball.getY() + ball.getRadius() > brick.getY() && ball.getY() - ball.getRadius() < brick.getY() + brick.getHeight()) {
                ball.setDy(-ball.getDy());
                brick.setDestroyed(true);
                score++;
                break; // Exit the loop after breaking one brick
            }
        }

        // Draw objects
        paddle.draw();
        ball.draw();
        for (auto& brick : bricks) {
            brick.draw();
        }
        topWall.draw();
        leftWall.draw();
        rightWall.draw();
        renderScore(score);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
