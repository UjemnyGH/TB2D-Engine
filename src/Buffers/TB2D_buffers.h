#pragma once

#include <iostream>
#include "../TB2D_engine.h"

namespace tb2d
{
    class TB2D_VAO
    {
    private:
        unsigned int ID;

    public:
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

    public:
        //create vertex buffer object
        void createVBO();
        //bind vertex buffer object
        void bindVBO(const float data[], const size_t dataSize, int usage, unsigned int index);
        //unbind vertex buffer object
        void unbindVBO();
        //delete vertex buffer object
        void deleteVBO();
    };

    typedef TB2D_VBO VBO;

    class TB2D_CBO
    {
    private:
        unsigned int ID;

    public:
        //create vertex buffer object
        void createCBO();
        //bind vertex buffer object
        void bindCBO(const float data[], const size_t dataSize, int usage, unsigned int index);
        //unbind vertex buffer object
        void unbindCBO();
        //delete vertex buffer object
        void deleteCBO();
    };

    typedef TB2D_CBO CBO;

    class TB2D_EBO
    {
    private:
        unsigned int ID;

    public:
        //create element buffer object
        void createEBO();
        //bind element buffer object
        void bindEBO(const unsigned int data[], const size_t dataSize, int usage);
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

    public:
        //create shaders
        void createShader(const std::string &vertexShaderName, const std::string &fragmentShaderName);
        //bind shader
        void bindShader();
        //get shader id
        unsigned int shaderID()
        {
            return ID;
        }
        //unbind shader
        void unbindShader();
        //delete shaders
        void deleteShader();  
    };

    typedef TB2D_Shaders Shader;

    class TB2D_Texture
    {
    private:
        unsigned int ID;

        int width, height, nrChannels;

    public:
        //create texture
        void createTexture();
        //bind texture
        void bindTexture(const std::string &path, const int &wrapping, const int &filtering);
        //unbind texture
        void unbindTexture();
        //delete texture
        void deleteTexture();
    };

    typedef TB2D_Texture Texture;
}