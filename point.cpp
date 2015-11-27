#include <GL/glfw.h>
#include <cmath>
#include "functions.h"
#include "point.h"
#include "bricks.h"

Point::Point(float x, float y, float sx, float sy): R(1), G(1), B(1)
{
    set(x, y);
    setSpeed(sx, sy);
}

void Point::set(float x, float y)
{
    this -> x = x;
    this -> y = y;
}

void Point::setSpeed(float sx, float sy)
{
    this -> speedX = sx;
    this -> speedY = sy;
}

void Point::setColor(float R, float G, float B)
{
    this -> R = R;
    this -> G = G;
    this -> B = B;
}

void Point::draw()
{
    glColor3f(R, G, B);
    glVertex2d(x, y);
}

void Point::reflect()
{
    if (x > 1 || x < - 1)
    {
        speedX =- speedX;
        setColor(random(0, 1), random(0, 1), random(0, 1));
    }

    if (y > 0.4 || y < -1)
    {
        speedY =- speedY;
        setColor(random(0, 1), random(0, 1), random(0, 1));
    }

    if (y > 0.4)
    {
        y = 0.4;
        hit();
    }
}

void Point::move()
{
    reflect();
    x += speedX;
    y += speedY;
}

extern int pointsCount;
extern int pointsArraySize;
extern Point *Pts;

void Point::hit()
{
    if(pointsCount < pointsArraySize)

    {
        Pts[pointsCount].set(x, 0.4-0.01);
        Pts[pointsCount].setSpeed(random(-0.001, 0.001), random(-0.001, 0));
        pointsCount++;
    }

}
