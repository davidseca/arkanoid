#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"

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

    // Create bricks
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 5; ++j) {
            bricks.emplace_back(60 * i + 50, 30 * j + 50);
        }
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // Paddle movement
        if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
            paddle.move(-paddle.speed);
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
            paddle.move(paddle.speed);
        }

        // Ball movement
        ball.update();

        // Collision detection and response (simplified)
        if (ball.x + ball.radius > paddle.x && ball.x - ball.radius < paddle.x + paddle.width &&
            ball.y + ball.radius > paddle.y && ball.y - ball.radius < paddle.y + paddle.height) {
            ball.dy = -ball.dy;
        }

        for (auto& brick : bricks) {
            if (!brick.destroyed && ball.x + ball.radius > brick.x && ball.x - ball.radius < brick.x + brick.width &&
                ball.y + ball.radius > brick.y && ball.y - ball.radius < brick.y + brick.height) {
                ball.dy = -ball.dy;
                brick.destroyed = true;
            }
        }

        // Draw objects
        paddle.draw();
        ball.draw();
        for (auto& brick : bricks) {
            brick.draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
