#pragma once

#include "Support.hpp"
#include "Material.hpp"

class Hit
{
public:
    bool hit;

    float distance;
    glm::vec3 position;
    glm::vec3 normal;

    const Material *material;

    Hit();
    Hit(bool hit, float distance, glm::vec3 position, glm::vec3 normal, const Material *material);
    ~Hit();
};