#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include "TB2D_window.h"

void tb2d::TB2D_window::createWindow(const std::string & name, int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutInitWindowSize(800, 600);

    glutCreateWindow(name.c_str());

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK)
    {
        std::cout << "Glew error\n";
    }

    if(!GLEW_VERSION_4_3)
    {
        std::cout << "Glew version error\n";
    }

    glGetError();
}