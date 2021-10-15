#pragma once

#include <iostream>
#include "../TB2D_engine.h"

namespace tb2d
{
    class TB2D_VAO
    {
    private:
        unsigned int ID;
        static unsigned int VAOCount;

    public:
        TB2D_VAO()
        {
            VAOCount++;
        }

        //create vertex array object
        void createVAO();
        //bind vertex array object
        void bindVAO();
        //unbind vertex array object
        void unbindVAO();
        //delete vertex array object
        void deleteVAO();
    };

    typedef TB2D_VAO VAO;

    class TB2D_VBO
    {
    private:
        unsigned int ID;
        static unsigned int VBOCount;

    public:
        TB2D_VBO()
        {
            VBOCount++;
        }

        //create vertex buffer object
        void createVBO();
        template<typename T>
        //bind vertex buffer object
        void bindVBO(T data[], size_t dataSize, int usage, unsigned int index);
        //unbind vertex buffer object
        void unbindVBO();
        //delete vertex buffer object
        void deleteVBO();
    };

    typedef TB2D_VBO VBO;

    class TB2D_EBO
    {
    private:
        unsigned int ID;
        static unsigned int EBOCount;

    public:
        TB2D_EBO()
        {
            EBOCount++;
        }

        //create element buffer object
        void createEBO();
        template<typename T>
        //bind element buffer object
        void bindEBO(T data[], size_t dataSize, int usage);
        //unbind element buffer object
        void unbindEBO();
        //delete element buffer object
        void deleteEBO();
    };

    typedef TB2D_EBO EBO;

    class TB2D_Shaders
    {
    private:
        unsigned int ID;
        static unsigned int ShadersCount;

    public:
        TB2D_Shaders()
        {
            ShadersCount++;
        }

        //create shaders
        void createShader(const std::string &vertexShaderName, const std::string &fragmentShaderName);
        //delete shaders
        void deleteShader();  
    };

    typedef TB2D_Shaders Shader;
}