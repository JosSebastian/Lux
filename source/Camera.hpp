#pragma once

#include "Support.hpp"

class Camera
{
public:
    Camera();
    Camera(glm::vec2 resolution, float fov, Transformation transformation);
    ~Camera();

private:
    glm::vec2 resolution;
    glm::vec2 fov;
    float aspect;

    Transformation transformation;
    glm::mat4 matrix;
};
