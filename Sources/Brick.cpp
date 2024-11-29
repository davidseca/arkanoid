#include "Brick.h"

float Brick::getX() const {
    return x;
}
void Brick::setX(float x) {
    this->x = x;
}

float Brick::getY() const {
    return y;
}
void Brick::setY(float y) {
    this->y = y;
}

float Brick::getWidth() const {
    return width;
}
void Brick::setWidth(float width) {
    this->width = width;
}

float Brick::getHeight() const {
    return height;
}
void Brick::setHeight(float height) {
    this->height = height;
}

bool Brick::isDestroyed() const {
    return destroyed;
}
void Brick::setDestroyed(bool destroyed) {
    this->destroyed = destroyed;
}

void Brick::draw() {
    if (!destroyed) {
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }
}