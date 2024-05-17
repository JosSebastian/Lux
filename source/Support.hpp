#pragma once

#include <iostream>

#include <memory>

#include <vector>
#include <string>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

struct Transformation
{
    glm::vec3 translate;
    glm::vec3 rotate;
    glm::vec3 scale;

    Transformation();
    Transformation(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
    ~Transformation();
};
