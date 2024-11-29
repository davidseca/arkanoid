#pragma once

#include <GLFW/glfw3.h>

// Brick class
class Brick {

    public:
    Brick(float x, float y) : x(x), y(y), width(60), height(20), destroyed(false) {}

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getWidth() const;
    void setWidth(float width);

    float getHeight() const;
    void setHeight(float height);

    bool isDestroyed() const;
    void setDestroyed(bool destroyed);

    void draw();

private:
    float x;
    float y;
    float width;
    float height;
    bool destroyed;
};