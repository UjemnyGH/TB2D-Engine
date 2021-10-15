#pragma once

#include "Buffers/TB2D_buffers.h"
#include <iostream>

namespace tb2d
{
    class TB2D_Square
    {
    private:
        static unsigned int SquareCount;
        float cpX, cpY, csX, csY, crX, crY;

    public:
        TB2D_Square()
        {
            SquareCount++;
        }

        //init square
        TB2D_Square(const std::string &vertShader, const std::string &fragShader, int &drawType);
        //draw square
        void draw(glm::mat4x4 &pvm, int &drawMode);
        //get position
        tb2d::vec2 GetPosition();
        //get scale
        tb2d::vec2 GetScale();
        //get rotation
        tb2d::vec2 GetRotation();
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
        void SetRotation(float x, float y);
        //set square rotation
        void SetRotation(tb2d::vec2 rotation);
        //set square rotation
        void SetRotation(glm::vec2 rotation);
        //delete square
        void deleteSquare();
    };

    typedef TB2D_Square Square;
}