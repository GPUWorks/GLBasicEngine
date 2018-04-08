#ifndef BUFFER_H
#define BUFFER_H

#include <OpenGL/gl3.h>
#include <vector>
#include "enum/bufferTarget.h"

class Buffer
{
public:
    Buffer();
    Buffer(BufferTarget target);
    ~Buffer();

    /**
     * Generate Buffer
     * @return GLuint
     */
    GLuint generate();

    /**
     * Set the data of a vertex buffer
     * @param data std::vector<float>
     */
    void setData(const std::vector<float> data);

    /**
     * Bind a buffer
     */
    void bind();

    /**
     * Unbind the GL_ARRAY_BUFFER
     */
    void unbind();

    /**
     * Delete the vertex buffer
     */
    void destroy();

private:
    GLuint id;
    std::vector<float> verticies;
    BufferTarget target;

};

#endif