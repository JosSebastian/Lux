#pragma once

#include "Ray.hpp"
#include "Hit.hpp"
#include "Material.hpp"

class Surface
{
public:
    Surface();
    Surface(const Transformation &transformation, const Material &material);
    ~Surface();

    virtual Hit Intersect(const Ray &ray, float min, float max) = 0;

protected:
    Transformation transformation;
    Material material;
};

class Sphere : public Surface
{
public:
    Sphere();
    Sphere(const Transformation &transformation, const Material &material);
    ~Sphere();

    Hit Intersect(const Ray &ray, float min, float max);
};
