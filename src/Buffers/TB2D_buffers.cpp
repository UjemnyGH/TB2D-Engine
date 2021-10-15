#define GLEW_STATIC
#include <GL/glew.h>
#include <fstream>
#include "TB2D_buffers.h"

unsigned int LoadShader(const int &type, const std::string &name)
{
    std::ifstream f;

    f.open(name, std::ios::binary);

    if(f.bad())
    {
        return -1;
    }

    f.seekg(0, std::ios::end);

    int len = static_cast<int>(f.tellg());

    f.seekg(0, std::ios::beg);

    char* srcBuffer = new char[(len + 1) * sizeof(char)];
    f.read(srcBuffer, len);
    srcBuffer[len] = '\0';
    f.close();

    unsigned int shader = glCreateShader(type);

    glShaderSource(shader, 1, const_cast<char**>(&srcBuffer), NULL);

    delete[] srcBuffer;

    glCompileShader(shader);

    return shader;
}

//      VAO
void tb2d::TB2D_VAO::createVAO()
{
    glGenVertexArrays(1, &ID);
}

void tb2d::TB2D_VAO::bindVAO()
{
    glBindVertexArray(ID);
}

void tb2d::TB2D_VAO::unbindVAO()
{
    glBindVertexArray(0);
}

void tb2d::TB2D_VAO::deleteVAO()
{
    glDeleteVertexArrays(1, &ID);
}

//      VBO
void tb2d::TB2D_VBO::createVBO()
{
    glGenBuffers(1, &ID);
}

template<typename T>
void tb2d::TB2D_VBO::bindVBO(T data[], size_t dataSize, int usage, unsigned int index)
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, usage);
    glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}

void tb2d::TB2D_VBO::unbindVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void tb2d::TB2D_VBO::deleteVBO()
{
    glDeleteBuffers(1, &ID);
}

//      EBO
void tb2d::TB2D_EBO::createEBO()
{
    glGenBuffers(1, &ID);
}

template<typename T>
void tb2d::TB2D_EBO::bindEBO(T data[], size_t dataSize, int usage)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, usage);
}

void tb2d::TB2D_EBO::unbindEBO()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void tb2d::TB2D_EBO::deleteEBO()
{
    glDeleteBuffers(1, &ID);
}

//      Shaders
void tb2d::TB2D_Shaders::createShader(const std::string &vertexShaderName, const std::string &fragmentShaderName)
{
    ID = glCreateProgram();
    glAttachShader(ID, LoadShader(GL_VERTEX_SHADER, vertexShaderName));
    glAttachShader(ID, LoadShader(GL_FRAGMENT_SHADER, fragmentShaderName));
    glLinkProgram(ID);
}

void tb2d::TB2D_Shaders::deleteShader()
{
    glDeleteShader(GL_VERTEX_SHADER);
    glDeleteShader(GL_FRAGMENT_SHADER);
}