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
     * Generate Buffer
     * @return GLuint
     */
    GLuint generate();

    /**
     * Set the data of a vertex buffer
     * @param data std::vector<float>
     */
    void setData(const std::vector<float> data) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(points) * points.size(), points.data(), GL_STATIC_DRAW);
    } 

    /**
     * Bind a buffer
     */
    void bind();

    /**
     * Unbind the GL_ARRAY_BUFFER
     */
    void unbind();
private:
    GLuint id;
    std::vector<float> verticies;

};

#endif