#include "buffer/vertex-array.h"

#include <OpenGL/gl3.h>

VertexArray::VertexArray(){}
VertexArray::~VertexArray(){}

GLuint VertexArray::generate() {
    glGenVertexArrays(1, &this->id);
    return id;
}