/**
* --------------------------------------------------------------------------
* GLPrimative
* --------------------------------------------------------------------------
* An enum that represents glenum primitive types(GL_TRIANGLES etc)
*
*/
#ifndef GLPRIMATIVE_H
#define GLPRIMATIVE_H
#include <OpenGL/gl3.h>

enum GLPrimative
{
    POINTS = 0X0000,
    LINES = 0X0001,
    LINE_LOOP = 0X0002,
    LINE_STRIP = 0X0003,
    TRIANGLES = 0X0004,
    TRIANGLE_STRIP = 0X0005,
    TRIANGLE_FAN = 0X0006
};

#endif