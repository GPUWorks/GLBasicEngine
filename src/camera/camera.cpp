#include "camera/camera.h"
#include <SFML/Window.hpp>
#include <iostream>

Camera::Camera(){}
Camera::~Camera(){}

glm::mat4 Camera::getViewMatrix() {
    return this->viewProjection;
}

void Camera::setup() {
    this->viewProjection = glm::lookAt(
        this->cameraPos,
        this->cameraPos + this->cameraFront,
        this->cameraUp
    );
}

void Camera::update(float delta, Shader::ShaderProgram& sp) {

    setup();
    sf::Mouse mouse;
    sf::Vector2i mpos = mouse.getPosition();

    glm::vec3 front;
    front.x = cos(glm::radians((float)mpos.x)) * cos(glm::radians((float)mpos.y));
    front.y = sin(glm::radians((float)mpos.y));
    front.z = sin(glm::radians((float)mpos.x)) * cos(glm::radians((float)mpos.y));
    this->cameraFront = glm::normalize(front);

    std::cout << mpos.x  << " " << mpos.y << std::endl;

    unsigned int viewProjLoc = glGetUniformLocation(sp.getShaderProgram(), "view");
    glUniformMatrix4fv(viewProjLoc, 1, GL_FALSE, glm::value_ptr(this->viewProjection));
}