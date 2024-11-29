#include "Wall.h"
#include <GLFW/glfw3.h>

float Wall::getX() const {
    return x;
}
void Wall::setX(float x) {
    this->x = x;
}

float Wall::getY() const {
    return y;
}
void Wall::setY(float y) {
    this->y = y;
}

float Wall::getWidth() const {
    return width;
}
void Wall::setWidth(float width) {
    this->width = width;
}

float Wall::getHeight() const {
    return height;
}
void Wall::setHeight(float height) {
    this->height = height;
}

void Wall::draw() const {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}