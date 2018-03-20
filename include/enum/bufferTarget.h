/**
* --------------------------------------------------------------------------
* BufferTarget
* --------------------------------------------------------------------------
* An enum represent different OpenGL buffer targets
*
*/
#ifndef BUFFER_TARGET_H
#define BUFFER_TARGET_H

#include <OpenGL/gl3.h>

enum BufferTarget
{
    ARRAY_BUFFER = GL_ARRAY_BUFFER,
    ELEMENT_BUFFER = GL_ELEMENT_ARRAY_BUFFER
};

#endif