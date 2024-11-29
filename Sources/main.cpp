#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"
#include "Wall.h"

#include <GLFW/glfw3.h>
#include <vector>

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Arkanoid Game", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Paddle paddle(350, 550);
    Ball ball(400, 300);
    std::vector<Brick> bricks;
    Wall topWall(0, 0, 800, 20); // Example wall at the top of the screen
    Wall leftWall(0, 0, 20, 600); // Wall on the left side of the screen
    Wall rightWall(780, 0, 20, 600); // Wall on the right side of the screen

    // Create bricks
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 5; ++col) {
            bricks.emplace_back(60 * row + 50, 30 * col + 50);
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
        if (ball.getX() - ball.getRadius() < 0 || ball.getX() + ball.getRadius() > 800) {
            ball.setDx(-ball.getDx());
        }
        if (ball.getY() - ball.getRadius() < topWall.getHeight()) {
            ball.setDy(-ball.getDy());
        }

        for (auto& brick : bricks) {
            if (!brick.isDestroyed() && ball.getX() + ball.getRadius() > brick.getX() && ball.getX() - ball.getRadius() < brick.getX() + brick.getWidth() &&
                ball.getY() + ball.getRadius() > brick.getY() && ball.getY() - ball.getRadius() < brick.getY() + brick.getHeight()) {
                ball.setDy(-ball.getDy());
                brick.setDestroyed(true);
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

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
