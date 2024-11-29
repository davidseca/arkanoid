#include <GLFW/glfw3.h>
#include <vector>

// Paddle class
class Paddle {
public:
    float x, y, width, height, speed;

    Paddle(float x, float y) : x(x), y(y), width(100), height(20), speed(6.0f) {}

    void move(float dx) {
        x += dx;
    }

    void draw() {
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
};

// Ball class
class Ball {
public:
    float x, y, radius, dx, dy;

    Ball(float x, float y) : x(x), y(y), radius(10), dx(4.0f), dy(-4.0f) {}

    void update() {
        x += dx;
        y += dy;
    }

    void draw() {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= 20; ++i) {
            float angle = i * 2.0f * 3.14159f / 20;
            glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
        }
        glEnd();
    }
};

// Brick class
class Brick {
public:
    float x, y, width, height;
    bool destroyed;

    Brick(float x, float y) : x(x), y(y), width(60), height(20), destroyed(false) {}

    void draw() {
        if (!destroyed) {
            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + width, y);
            glVertex2f(x + width, y + height);
            glVertex2f(x, y + height);
            glEnd();
        }
    }
};

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