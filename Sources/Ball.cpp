#include "Ball.h"

#include <GLFW/glfw3.h>

#include <cmath>

Ball::Ball(float x, float y)
    : x(x)
    , y(y)
    , radius(10)
    , dx(4.0f)
    , dy(-4.0f)
{
    // empty
}

float Ball::getX() const {
    return x;
}

void Ball::setX(float x) {
    this->x = x;
}

float Ball::getY() const {
    return y;
}

void Ball::setY(float y) {
    this->y = y;
}

float Ball::getRadius() const {
    return radius;
}

void Ball::setRadius(float radius) {
    this->radius = radius;
}

float Ball::getDx() const {
    return dx;
}

void Ball::setDx(float dx) {
    this->dx = dx;
}

float Ball::getDy() const {
    return dy;
}

void Ball::setDy(float dy) {
    this->dy = dy;
}

void Ball::update() {
    x += dx;
    y += dy;
}

void Ball::draw() {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 20; ++i) {
        float angle = i * 2.0f * 3.14159f / 20;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}