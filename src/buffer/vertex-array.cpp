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