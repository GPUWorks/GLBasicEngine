#include "buffer/buffer.h"
#include <OpenGL/gl3.h>

Buffer::Buffer(){}
Buffer::~Buffer(){}

GLuint Buffer::generate()
{
    glGenBuffers(1, &this->id);
    return id;
}

void Buffer::setData(const std::vector<float> data) {
    glBufferData(GL_ARRAY_BUFFER, sizeof(data) * data.size(), data.data(), GL_STATIC_DRAW);
}

void Buffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}

void Buffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
