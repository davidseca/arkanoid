#pragma once

class Wall {
public:
    Wall(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getWidth() const;
    void setWidth(float width);

    float getHeight() const;
    void setHeight(float height);

    void draw() const;

private:
    float x;
    float y;
    float width;
    float height;
};