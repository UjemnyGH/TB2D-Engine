#pragma once

#include "Buffers/TB2D_buffers.h"
#include "TB2D_engine.h"
#include <iostream>

namespace tb2d
{
    static const std::string &textureVS = "data/shaders/texture/textureVS.glsl";
    static const std::string &textureFS = "data/shaders/texture/textureFS.glsl";

    static const std::string &colorVS = "data/shaders/texture/colorVS.glsl";
    static const std::string &colorFS = "data/shaders/texture/colorFS.glsl";

    enum tf
    {
        mirrored = GL_MIRRORED_REPEAT,
        repeat = GL_REPEAT,
        edge = GL_CLAMP_TO_EDGE,
        border = GL_CLAMP_TO_BORDER
    };

    class TB2D_Square
    {
    private:
        float cpX, cpY, csX, csY, cr;
        color squareColor;
        Texture texture;

        Shader sh;
        VAO vao;
        VBO vbo;
        VBO tco;
        CBO cbo;
        EBO ebo;

        float vertices[2 * 4] = {
            1.0f, 1.0f,
            -1.0f, 1.0f,
            1.0f, -1.0f,
            -1.0f, -1.0f
        };

        const float psrConst[2 * 4] = {
            1.0f, 1.0f,
            -1.0f, 1.0f,
            1.0f, -1.0f,
            -1.0f, -1.0f
        };

        const float texCoords[2 * 4] = {
            1.0f, 1.0f,
            0.0f, 1.0f,
            1.0f, 0.0f,
            0.0f, 0.0f
        };

        unsigned int indices[2 * 3] = {
            0, 1, 2,
            1, 2, 3
        };

        float colorSq[3 * 4] = {
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f
        };

        float borderColor[4] = {1.0f, 1.0f, 1.0f, 0.0f};

    public:
        //init square
        void init(const std::string &vertShader, const std::string &fragShader, const int &drawType);
        //init square with texture
        void init(const std::string &vertShader, const std::string &fragShader, const std::string &texturePath, const int &drawType);
        //draw square
        void draw(const int &drawMode);
        //get position
        tb2d::vec2 GetPosition();
        //get scale
        tb2d::vec2 GetScale();
        //get rotation
        float GetRotation();
        //get square color
        tb2d::color GetColor();
        //set square position
        void SetPosition(float x, float y);
        //set square position
        void SetPosition(tb2d::vec2 position);
        //set square position
        void SetPosition(glm::vec2 position);
        //set square scale
        void SetScale(float scale);
        //set square scale
        void SetScale(float x, float y);
        //set square scale
        void SetScale(tb2d::vec2 scale);
        //set square scale
        void SetScale(glm::vec2 scale);
        //set square rotation
        void SetRotation(float rotation);
        //set square color
        void SetColor(float r, float g, float b);
        //set square color
        void SetColor(tb2d::color squareCol);
        //set square texture
        void SetTexture(const std::string &path, const int &wrapping, const int &filtering);
        //delete square
        void deleteSquare();
    };

    typedef TB2D_Square Square;
}