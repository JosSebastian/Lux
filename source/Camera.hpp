#pragma once

#include "Support.hpp"
#include "Ray.hpp"

class Camera
{
public:
    Camera();
    Camera(int width, int height, float fov, Transformation transformation);
    ~Camera();

    Ray CreateRay(int x, int y);

private:
    int width;
    int height;

    glm::vec2 fov;
    float aspect;

    Transformation transformation;
    glm::mat4 matrix;
};
