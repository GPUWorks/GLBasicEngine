#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader/shaderProgram.h"

class Camera
{
public:
    Camera();
    ~Camera();

    /**
     * Setup the camera;
     */
    void setup();

    void update(float delta, Shader::ShaderProgram& sp);

    /**
     * Get the view matrix
     * @return glm::mat4
     */
    glm::mat4 getViewMatrix();

private:
    glm::mat4 viewProjection;
    glm::vec3 cameraPos = glm::vec3(0.0,0.0, -20.0);
    glm::vec3 cameraFront = glm::vec3(0.0,0.0,1.0);
    glm::vec3 cameraUp = glm::vec3(0.0,1.0,0.0);
};

#endif