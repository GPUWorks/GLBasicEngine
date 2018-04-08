#include "buffer/vertex-array.h"

#include <OpenGL/gl3.h>

VertexArray::VertexArray(){}
VertexArray::~VertexArray(){}

GLuint VertexArray::generate() {
    glGenVertexArrays(1, &this->id);
    return id;
}

void VertexArray::bind() {
    glBindVertexArray(this->id);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

void VertexArray::destroy() {
    glDeleteVertexArrays(1, &this->id);
}

void VertexArray::enableAttrib(int pos, int size, int stride) {
    glEnableVertexAttribArray(pos);
    glVertexAttribPointer(
       pos,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       size,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       stride,                  // stride
       (void*)0            // array buffer offset
    );
}