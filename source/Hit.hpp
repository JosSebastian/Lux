#pragma once

#include "Support.hpp"
#include "Material.hpp"

class Material;

class Hit
{
public:
    bool hit;

    float distance;
    glm::vec3 position;
    glm::vec3 normal;

    std::shared_ptr<Material> material;

    Hit();
    Hit(bool hit, float distance, glm::vec3 position, glm::vec3 normal, std::shared_ptr<Material> material);
    ~Hit();
};