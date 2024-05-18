#pragma once

#include "Support.hpp"
#include "Ray.hpp"

class Camera
{
public:
    Camera();
    Camera(int width, int height, float fov, Transform transform);
    ~Camera();

    Ray CreateRay(int x, int y, bool random);

private:
    int width;
    int height;

    glm::vec2 fov;
    float aspect;

    Transform transform;
    glm::mat4 matrix;
};
