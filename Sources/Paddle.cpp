#include "Paddle.h"

#include <GLFW/glfw3.h>

Paddle::Paddle(float x, float y, float width, float height, float speed)
    : x(x)
    , y(y)
    , width(width)
    , height(height)
    , speed(speed)
{
    // empty
}

float Paddle::getX() const {
    return x;
}
void Paddle::setX(float x) {
    this->x = x;
}

float Paddle::getY() const {
    return y;
}
void Paddle::setY(float y) {
    this->y = y;
}

float Paddle::getWidth() const {
    return width;
}
void Paddle::setWidth(float width) {
    this->width = width;
}

float Paddle::getHeight() const {
    return height;
}
void Paddle::setHeight(float height) {
    this->height = height;
}

float Paddle::getSpeed() const {
    return speed;
}
void Paddle::setSpeed(float speed) {
    this->speed = speed;
}

void Paddle::move(float dx) {
    x += dx;
}

void Paddle::draw() {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}