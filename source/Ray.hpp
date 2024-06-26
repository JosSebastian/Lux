#pragma once

#include "Support.hpp"

class Ray
{
public:
    glm::vec3 point;
    glm::vec3 direction;

    Ray();
    Ray(glm::vec3 point, glm::vec3 direction);
    ~Ray();

    glm::vec3 At(float time);
};
