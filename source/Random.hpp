#pragma once

#include "Support.hpp"

class Random
{
public:
    Random();
    Random(unsigned long seed);
    ~Random();

    float CreateRandom();

    glm::vec3 CreateSphere();
    glm::vec3 CreateHemisphere(glm::vec3 normal);

private:
    std::mt19937_64 generator;
    std::uniform_real_distribution<float> distribution;
};
