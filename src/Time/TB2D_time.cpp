#include <GL/freeglut.h>
#include "TB2D_time.h"

float tb2d::TB2D_time::GetTime()
{
    return static_cast<float>(glutGet(GLUT_ELAPSED_TIME));
}

float tb2d::TB2D_time::GetDeltaTime()
{
    lastFrame = currentFrame;
    currentFrame = glutGet(GLUT_ELAPSED_TIME);

    deltaFrame = lastFrame - currentFrame;

    return deltaFrame;
}