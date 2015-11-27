#include "window.h"
#include <GL/glfw.h>

void init()
{
    int width = 640, height = 480;

    glfwInit();

    if( !glfwOpenWindow( width, height, 0, 0, 0, 0, 0, 0, GLFW_WINDOW ) )
    {
        glfwTerminate();
        return;
    }
    glfwSetWindowTitle("Rainbow Ping Pong");

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

}

bool running() {
    return !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam( GLFW_OPENED);
}

