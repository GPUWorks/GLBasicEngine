#include "camera/camera.h"

Camera::Camera(){}
Camera::~Camera(){}

glm::mat4 Camera::getViewMatrix() {
    return this->viewProjection;
}

void Camrea::setup() {
    this->viewProjection = glm::lookAt(
        this->cameraPos,
        this->cameraPos + this->cameraFront,
        this->cameraUp
    );
}

void update(float delta, Shader& sp) {
    unsigned int viewProjLoc = glGetUniformLocation(sp, "view");
    glUniformMatrix4fv(viewProjLoc, 1, GL_FALSE, glm::value_ptr(this->viewProjection));
}