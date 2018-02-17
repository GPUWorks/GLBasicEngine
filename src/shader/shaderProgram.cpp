#include "shader/ShaderProgram.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <OpenGL/gl3.h>

namespace Shader
{
    
    ShaderProgram::ShaderProgram(){}
    ShaderProgram::~ShaderProgram(){}

    GLuint ShaderProgram::loadShaders(const char * vertex_file_path,const char * fragment_file_path){
        // Create the shaders
        GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

        // Read the Vertex Shader code from the file
        std::string VertexShaderCode;
        std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
        if(VertexShaderStream.is_open()){
            std::stringstream sstr;
            sstr << VertexShaderStream.rdbuf();
            VertexShaderCode = sstr.str();
            VertexShaderStream.close();
        }else{
            printf("Impossible to open %s. Are you in the right directory ?\n", vertex_file_path);
            getchar();
            return 0;
        }

        // Read the Fragment Shader code from the file
        std::string FragmentShaderCode;
        std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
        if(FragmentShaderStream.is_open()){
            std::stringstream sstr;
            sstr << FragmentShaderStream.rdbuf();
            FragmentShaderCode = sstr.str();
            FragmentShaderStream.close();
        }

        GLint Result = GL_FALSE;
        int InfoLogLength;


        // Compile Vertex Shader
        printf("Compiling shader : %s\n", vertex_file_path);
        char const * VertexSourcePointer = VertexShaderCode.c_str();
        glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
        glCompileShader(VertexShaderID);

        // Check Vertex Shader
        glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if ( InfoLogLength > 0 ){
            std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
            glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
            printf("%s\n", &VertexShaderErrorMessage[0]);
        }



        // Compile Fragment Shader
        printf("Compiling shader : %s\n", fragment_file_path);
        char const * FragmentSourcePointer = FragmentShaderCode.c_str();
        glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
        glCompileShader(FragmentShaderID);

        // Check Fragment Shader
        glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if ( InfoLogLength > 0 ){
            std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
            glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
            printf("%s\n", &FragmentShaderErrorMessage[0]);
        }

        // Link the program
        printf("Linking program\n");
        this->program = glCreateProgram();
        glAttachShader(this->program, VertexShaderID);
        glAttachShader(this->program, FragmentShaderID);
        glLinkProgram(this->program);

        // Check the program
        glGetProgramiv(this->program, GL_LINK_STATUS, &Result);
        glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if ( InfoLogLength > 0 ){
            std::vector<char> ProgramErrorMessage(InfoLogLength+1);
            glGetProgramInfoLog(this->program, InfoLogLength, NULL, &ProgramErrorMessage[0]);
            printf("%s\n", &ProgramErrorMessage[0]);
        }

        
        glDetachShader(this->program, VertexShaderID);
        glDetachShader(this->program, FragmentShaderID);
        
        glDeleteShader(VertexShaderID);
        glDeleteShader(FragmentShaderID);

        std::cout << "Shader Deleted" << std::endl;

        return this->program;
    }

    GLuint ShaderProgram::getShaderProgram() const {
        return this->program;
    }
    
    void ShaderProgram::uniform1f(const std::string& name, float value ) {
        glm::mat4 trans = glm::translate(trans, glm::vec3(std::sin(c) * -10, 0.5f, 0.0f));
        unsigned int uniform1f = glGetUniformLocation(sp.getShaderProgram(), name);
        glUniformMatrix4fv(uniform1f, 1, GL_FALSE, glm::value_ptr(trans));
    }
}

