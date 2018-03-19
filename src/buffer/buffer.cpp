#include "buffer/buffer.h"

Buffer::Buffer(){}
Buffer::~Buffer(){}

void Buffer::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
