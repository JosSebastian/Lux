#pragma once

#include "Support.hpp"

class Camera
{
public:
    Camera();
    Camera(const glm::vec2 &resolution, float fov, const Transformation &transformation);
    ~Camera();

    void Log();

private:
    glm::vec2 resolution;
    glm::vec2 fov;
    float aspect;

    Transformation transformation;
    glm::mat4 matrix;
};
