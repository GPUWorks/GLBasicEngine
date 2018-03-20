#include "buffer/buffer.h"
#include <OpenGL/gl3.h>

Buffer::Buffer(){}
Buffer::~Buffer(){}

GLuint Buffer::generate()
{
    glGenBuffers(1, &this->id);
    return id;
}

void Buffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
