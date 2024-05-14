#pragma once

#include <glm/glm.hpp>

struct Transformation
{
    glm::vec3 translate;
    glm::vec3 rotate;
    glm::vec3 scale;

    Transformation();
    Transformation(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
    ~Transformation();

    void Log();
};
