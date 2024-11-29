#pragma once

// Ball class
class Ball {
public:

    Ball(float x, float y);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getRadius() const;
    void setRadius(float radius);

    float getDx() const;
    void setDx(float dx);

    float getDy() const;
    void setDy(float dy);

    void update();
    void draw();

private:
    float x;
    float y;
    float radius;
    float dx;
    float dy;
};