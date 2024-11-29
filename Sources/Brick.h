#pragma once

#include <GLFW/glfw3.h>

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