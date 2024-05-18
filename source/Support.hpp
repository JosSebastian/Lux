#pragma once

#include <iostream>

#include <memory>

#include <random>

#include <vector>
#include <string>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

struct Transform
{
    glm::vec3 translate;
    glm::vec3 rotate;
    glm::vec3 scale;

    Transform();
    Transform(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
    ~Transform();
};
