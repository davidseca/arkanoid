#pragma once

#include <GLFW/glfw3.h>

#include <cmath>

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