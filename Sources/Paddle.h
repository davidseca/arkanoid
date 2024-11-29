#pragma once

#include <GLFW/glfw3.h>

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