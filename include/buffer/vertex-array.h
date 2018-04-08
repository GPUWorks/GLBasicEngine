#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <OpenGL/gl3.h>

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    /**
     * Generate an vertex array
     * @return the id
     */
    GLuint generate();

    /**
     * Bind the vertex array
     */
    void bind();

    /**
     * Unbind the vertex array
     */
    void unbind();

    /**
     * Delete the VAO
     */
    void destroy();


private:
    GLuint id;

};

#endif