#ifndef SHADER_PROG_H
#define SHADER_PROG_H

#include <OpenGL/gl3.h>

namespace Shader
{
    class ShaderProgram {
    public:
        ShaderProgram();
        ~ShaderProgram();

        /**
         * Load the shader
         * @param  vertex_file_path   Vertex Shader Path
         * @param  fragment_file_path Fragment Shader Path
         */
        GLuint loadShaders(const char * vertex_file_path,const char * fragment_file_path);

        /**
         * Get the shader program
         */
        GLuint getShaderProgram() const;


    private:
        GLuint program;


    };
}


#endif