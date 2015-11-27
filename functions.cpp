#include <GL/glfw.h>
#include "functions.h"
#include <cstdlib>

GLuint LoadTexture(const char* TextureName)
{
   GLuint Texture;
   glGenTextures(1,&Texture);
   glBindTexture(GL_TEXTURE_2D,Texture);

   if(glfwLoadTexture2D(TextureName, GLFW_BUILD_MIPMAPS_BIT))
   {
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      return Texture;
   } else return -1;
}

void drawRainbow(GLuint Rainbow){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,Rainbow);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0);
        glVertex2f(-1,1);

        glTexCoord2f(1,0);
        glVertex2f(1,1);

        glTexCoord2f(1,1);
        glVertex2f(1,0.4);

        glTexCoord2f(0,1);
        glVertex2f(-1,0.4);
    glEnd();

    glDisable( GL_TEXTURE_2D );
}

float random(float a, float b)
{
    return (rand()/(float)RAND_MAX)*(b-a)+a;
}

