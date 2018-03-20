#include "buffer/buffer.h"
#include "enum/bufferTarget.h"
#include <OpenGL/gl3.h>

Buffer::Buffer(){}
Buffer::~Buffer(){}

GLuint Buffer::generate()
{
    glGenBuffers(1, &this->id);
    return id;
}

void Buffer::setData(const std::vector<float> data) {
    glBufferData(BufferTarget::ARRAY_BUFFER, sizeof(data) * data.size(), data.data(), GL_STATIC_DRAW);
}

void Buffer::bind()
{
    glBindBuffer(BufferTarget::ARRAY_BUFFER, this->id);
}

void Buffer::unbind()
{
    glBindBuffer(BufferTarget::ARRAY_BUFFER, 0);
}
