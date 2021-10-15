#pragma once

#include <glm/glm.hpp>

namespace tb2d
{
    struct TB2D_Color
    {
        float r;
        float g;
        float b;

        TB2D_Color()
        {

        }

        TB2D_Color(float &R, float &G, float &B)
        {
            r = R;
            g = G;
            b = B;
        }
    };

    typedef TB2D_Color color;

    struct TB2D_Vec2
    {
        float x;
        float y;

        TB2D_Vec2()
        {

        }

        template<typename T>
        TB2D_Vec2(T &X, T &Y)
        {
            x = X;
            y = Y;
        }

        glm::vec2 vec2Conv()
        {
            return glm::vec2(x, y);
        }

        glm::vec2 vec2Conv(float &X, float &Y)
        {
            return glm::vec2(X, Y);
        }
    };

    typedef TB2D_Vec2 vec2;

    struct TB2D_Dvec2
    {
        float x;
        float y;

        TB2D_Dvec2()
        {

        }

        template<typename T>
        TB2D_Dvec2(T &X, T &Y)
        {
            x = X;
            y = Y;
        }

        glm::dvec2 dvec2Conv()
        {
            return glm::dvec2(x, y);
        }

        glm::dvec2 dvec2Conv(float &X, float &Y)
        {
            return glm::dvec2(X, Y);
        }
    };

    typedef TB2D_Dvec2 dvec2;
}