#ifndef BUFFER_H
#define BUFFER_H

#include <OpenGL/gl3.h>
#include <vector>

class Buffer
{
public:
    Buffer();
    ~Buffer();

    /**
     * Unbind the GL_ARRAY_BUFFER
     */
    void unbind();
private:
    std::vector<float> verticies;

};

#endif