#define GLEW_STATIC
#include <GL/glew.h>
#include <iostream>
#include "Buffers/TB2D_buffers.h"
#include "TB2D_square.h"

void tb2d::TB2D_Square::init(const std::string &vertShader, const std::string &fragShader, const int &drawType)
{
    sh.createShader(vertShader, fragShader);

    vao.createVAO();
    vao.bindVAO();

    vbo.createVBO();
    vbo.bindVBO(vertices, sizeof(vertices), drawType, 0);

    cbo.createCBO();
    cbo.bindCBO(colorSq, sizeof(colorSq), drawType, 1);

    ebo.createEBO();
    ebo.bindEBO(indices, sizeof(indices), drawType);

    vao.unbindVAO();
}

void tb2d::TB2D_Square::init(const std::string &vertShader, const std::string &fragShader, const std::string &texturePath, const int &drawType)
{
    sh.createShader(vertShader, fragShader);

    vao.createVAO();
    vao.bindVAO();

    vbo.createVBO();
    vbo.bindVBO(vertices, sizeof(vertices), drawType, 0);

    cbo.createCBO();
    cbo.bindCBO(colorSq, sizeof(colorSq), drawType, 1);

    tco.createVBO();
    tco.bindVBO(texCoords, sizeof(texCoords), drawType, 2);

    ebo.createEBO();
    ebo.bindEBO(indices, sizeof(indices), drawType);

    texture.createTexture();
    texture.bindTexture(texturePath, tf::repeat, GL_NEAREST);
    
    vao.unbindVAO();
}

void tb2d::TB2D_Square::draw(const int &drawMode)
{
    vao.bindVAO();
    sh.bindShader();

    glUniform1i(glGetUniformLocation(sh.shaderID(), "tex"), 0);

    glDrawElements(drawMode, sizeof(vertices) / 4, GL_UNSIGNED_INT, NULL);

    sh.unbindShader();
    vao.unbindVAO();
}

tb2d::vec2 tb2d::TB2D_Square::GetPosition()
{
    return tb2d::vec2(cpX, cpY);
}

tb2d::vec2 tb2d::TB2D_Square::GetScale()
{
    return tb2d::vec2(csX, csY);
}

float tb2d::TB2D_Square::GetRotation()
{
    return cr;
}

tb2d::color tb2d::TB2D_Square::GetColor()
{
    return squareColor;
}

void tb2d::TB2D_Square::SetPosition(float x, float y)
{
    cpX = x;
    cpY = y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] + x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] + y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetPosition(tb2d::vec2 position)
{
    cpX = position.x;
    cpY = position.y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] + position.x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] + position.y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetPosition(glm::vec2 position)
{
    cpX = position.x;
    cpY = position.y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] + position.x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] + position.y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetScale(float scale)
{
    csX = scale;
    csY = scale;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] * scale;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] * scale;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetScale(float x, float y)
{
    csX = x;
    csY = y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] * x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] * y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetScale(tb2d::vec2 scale)
{
    csX = scale.x;
    csY = scale.y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] + scale.x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] + scale.y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetScale(glm::vec2 scale)
{
    csX = scale.x;
    csY = scale.y;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = psrConst[i * 2] + scale.x;
        vertices[(i * 2) + 1] = psrConst[(i * 2) + 1] + scale.y;
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetRotation(float rotation)
{
    cr = rotation;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        vertices[i * 2] = (sin(rotation) + cos(rotation)) * psrConst[i * 2];
        vertices[(i * 2) + 1] = (cos(rotation) - sin(rotation)) * psrConst[(i * 2) + 1];
    }

    vbo.bindVBO(vertices, sizeof(vertices), GL_DYNAMIC_DRAW, 0);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetColor(float r, float g, float b)
{
    squareColor.r = r;
    squareColor.g = g;
    squareColor.b = b;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        colorSq[i * 3] = r;
        colorSq[(i * 3) + 1] = g;
        colorSq[(i * 3) + 2] = b;
    }

    cbo.bindCBO(colorSq, sizeof(colorSq), GL_DYNAMIC_DRAW, 1);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetColor(tb2d::color squareCol)
{
    squareColor.r = squareCol.r;
    squareColor.g = squareCol.g;
    squareColor.b = squareCol.b;

    vao.bindVAO();

    for(int i = 0; i < 4; i++)
    {
        colorSq[i * 3] = squareCol.r;
        colorSq[(i * 3) + 1] = squareCol.g;
        colorSq[(i * 3) + 2] = squareCol.b;
    }

    cbo.bindCBO(colorSq, sizeof(colorSq), GL_DYNAMIC_DRAW, 1);
    vao.unbindVAO();
}

void tb2d::TB2D_Square::SetTexture(const std::string &path, const int &wrapping, const int &filtering)
{
    sh.bindShader();
    vao.bindVAO();

    texture.bindTexture(path, wrapping, filtering);

    vao.unbindVAO();
    sh.unbindShader();
    texture.unbindTexture();
}

void tb2d::TB2D_Square::deleteSquare()
{
    vao.deleteVAO();
    vbo.deleteVBO();
    cbo.deleteCBO();
    tco.deleteVBO();
    texture.deleteTexture();
    ebo.deleteEBO();
}