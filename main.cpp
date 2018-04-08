#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <OpenGL/gl3.h>
#include <vector>
#include <cmath>
#include "shader/shaderProgram.h"
#include "buffer/buffer.h"
#include "buffer/vertex-array.h"
#include "camera/camera.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    const int MAX = 50;

    sf::Window window(sf::VideoMode(1024, 768), "OpenGL", sf::Style::Default, settings);

    Shader::ShaderProgram sp;
    sp.loadShaders("../assets/vsh.glsl", "../assets/fsh.glsl");

    GLuint VAO;
    GLuint VBO;

    VertexArray vertexArr;
    vertexArr.generate();
    vertexArr.bind();

       std::vector<float> points = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,

        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,

        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,

        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,

        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
    }; 

    Camera camera;

    Buffer b;
    b.generate();
    b.bind();
    b.setData(points);
    b.unbind();

    glEnableVertexAttribArray(0);
    b.bind();
    glVertexAttribPointer(
       0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
       3,                  // size
       GL_FLOAT,           // type
       GL_FALSE,           // normalized?
       0,                  // stride
       (void*)0            // array buffer offset
    );

    int c = 0;

    sf::Clock clock;
    float delta = 0;

    std::vector<glm::vec3> modelPosition;

    for (int i = 0; i <= MAX - 1; ++i)
    {
        float x = rand() % 50;
        float y = rand() % 50;
        float z = rand() % 50;
        glm::vec3 v(x,y,z);
        modelPosition.push_back(v);
    }

   // run the main loop
    bool running = true;
    while (running)
    {

        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.1f, -0.5f, -10.0f));
        model = glm::rotate(model, delta, glm::vec3(0.4f, 0.8f, 1.0f));

        glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 1000.0f);  

        unsigned int proj = glGetUniformLocation(sp.getShaderProgram(), "projection");
        glUniformMatrix4fv(proj, 1, GL_FALSE, glm::value_ptr(projection));


        camera.update(delta, sp);


        unsigned int modelLoc = glGetUniformLocation(sp.getShaderProgram(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));


        unsigned int col = glGetUniformLocation(sp.getShaderProgram(), "tcol");
        glUniform1f(col, delta);

        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        for (int i = 0; i <= MAX - 1; ++i)
        {
            glm::mat4 model;
            model = glm::translate(model, modelPosition.at(i));
            unsigned int modelLoc = glGetUniformLocation(sp.getShaderProgram(), "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            glDrawArrays(GL_TRIANGLES, 0, 36 );
        }

        glUseProgram(sp.getShaderProgram());

        // draw...
        glDrawArrays(GL_TRIANGLES, 0, 36 );


        // end the current frame (internally swaps the front and back buffers)
        window.display();

        delta = clock.getElapsedTime().asSeconds();
    }
 

    return 0;
}
