#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
    Camera();
    ~Camera();
private:
    glm::mat4 viewProjection;
    glm::vec3 cameraPos = glm::vec3(0.0,0.0,0.0);
    glm::vec3 cameraFront = glm::vec3(0.0,0.0,1.0);
    glm::vec3 cameraUp = glm::vec3(0.0,0.0,1.0);
};

#endif