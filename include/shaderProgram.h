#ifndef SHADER_PROG_H
#define SHADER_PROG_H

#include <OpenGL/gl3.h>

class ShaderProgram {
public:
    ShaderProgram();
    ~ShaderProgram();

    GLuint program;

    GLuint loadShaders(const char * vertex_file_path,const char * fragment_file_path);


};

#endif