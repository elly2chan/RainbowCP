#include <GL/glfw.h>
#include "window.h"
#include "functions.h"
#include "point.h"
#include "bricks.h"
#include <cmath>

int pointsArraySize = 10000;
int pointsCount = 1;
Point* Pts;

int main()
{
    init();

    GLuint Rainbow = LoadTexture("rainbow.tga");

    glPointSize(5.5);
    Pts = new Point[pointsArraySize];
    Pts[0].set(0,-1);
    Pts[0].setSpeed(-0.001, 0.001);

    while(running())
    {

        glClear( GL_COLOR_BUFFER_BIT );


        glBegin( GL_POINTS );

            for(int i=0;i<pointsCount;i++)
            {
                Pts[i].draw();
                Pts[i].move();
            }

        glEnd();


/*        glColor3f(0.5f, 1.0f, 0.5f);
        glBegin(GL_QUADS);
            glVertex2f(1,-1);
            glVertex2f(-1,-1);
            glVertex2f(-1,-0.9);
            glVertex2f(1,-0.9);
        glEnd(); */


        drawRainbow(Rainbow);

        glfwSwapBuffers();
    }

    glfwTerminate();

    return 0;
}
