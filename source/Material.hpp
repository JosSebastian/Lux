#pragma once

#include "Support.hpp"
#include "Hit.hpp"

class Hit;

class Material
{
public:
    Material();
    ~Material();

    virtual glm::vec3 Emissivity(Hit hit, glm::vec3 in, glm::vec3 out);
    virtual glm::vec3 Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out);

    virtual bool Halt();
};

class Lambertian : public Material
{
public:
    const glm::vec3 albedo;

    Lambertian();
    Lambertian(glm::vec3 albedo);
    ~Lambertian();

    glm::vec3 Emissivity(Hit hit, glm::vec3 in, glm::vec3 out);
    glm::vec3 Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out);

    bool Halt();
};

class Light : public Material
{
public:
    const glm::vec3 radiance;

    Light();
    Light(glm::vec3 radiance);
    ~Light();

    glm::vec3 Emissivity(Hit hit, glm::vec3 in, glm::vec3 out);
    glm::vec3 Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out);

    bool Halt();
};