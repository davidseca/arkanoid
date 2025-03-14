#pragma once

// Paddle class
class Paddle {

public:
    Paddle(float x, float y, float width, float height, float speed);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    float getWidth() const;
    void setWidth(float width);

    float getHeight() const;
    void setHeight(float height);

    float getSpeed() const;
    void setSpeed(float speed);

    void move(float dx);
    void draw();

private:
    float x;
    float y;
    float width;
    float height;
    float speed;
};