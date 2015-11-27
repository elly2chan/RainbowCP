#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        float x;
        float y;

        float speedX;
        float speedY;

        float R,G,B;

        Point(float x = 0, float y = 0, float sx = 0, float sy = 0);

        void set(float x, float y);
        void setSpeed(float x, float y);
        void setColor(float, float, float);

        void move();
        void reflect();
        void hit();

        void draw();

};

#endif // POINT_H
