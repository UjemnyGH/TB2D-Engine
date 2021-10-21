#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <future>
#include "Window/TB2D_window.h"
#include "TB2D_square.h"

void Init();
void Display();
void Reshape(int w, int h);
void Delete();

float scale = 0.5f;

tb2d::Square sq;
tb2d::GameWindow window;

void mainLoop()
{
    while(true)
    {
        
    }
}

int main(int argc, char** argv)
{
    window.createWindow("Window", argc, argv);

    std::future<void> mainLoopTh = std::async(mainLoop);

    Init();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);

    glutMainLoop();

    Delete();

    return 0;
}

void Init()
{
    glClearColor(0.2f, 0.8f, 1.0f, 1.0f);

    sq.init(tb2d::textureVS, tb2d::textureFS, "data/textures/texture.png", GL_DYNAMIC_DRAW);
}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sq.SetColor(0.2f, 0.4f, 0.0f);
    sq.draw(GL_TRIANGLES);

    glutSwapBuffers();
}

void Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
}

void Delete()
{
    sq.deleteSquare();
}