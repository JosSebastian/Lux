#pragma once

#include "Support.hpp"

class Ray
{
public:
    glm::vec3 point;
    glm::vec3 direction;

    Ray();
    Ray(const glm::vec3 &point, const glm::vec3 &direction);
    ~Ray();

    void Log();

    glm::vec3 At(float time);
};
