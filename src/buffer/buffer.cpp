#include "buffer/buffer.h"
#include "enum/bufferTarget.h"
#include <OpenGL/gl3.h>

Buffer::Buffer(){}
Buffer::Buffer(BufferTarget target){
    this->target = target;
}
Buffer::~Buffer(){}

GLuint Buffer::generate()
{
    glGenBuffers(1, &this->id);
    return id;
}

void Buffer::setData(const std::vector<float> data) {
    glBufferData(this->target, sizeof(data) * data.size(), data.data(), GL_STATIC_DRAW);
}

void Buffer::bind()
{
    glBindBuffer(this->target, this->id);
}

void Buffer::unbind()
{
    glBindBuffer(this->target, 0);
}

void Buffer::destroy()
{
    glDeleteBuffers(1, &this->id);
}
