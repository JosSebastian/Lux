#pragma once

#include "Ray.hpp"
#include "Hit.hpp"
#include "Material.hpp"

class Surface
{
public:
    Surface();
    Surface(Transformation transformation, Material material);
    ~Surface();

    virtual Hit Intersect(Ray ray, float min, float max) = 0;

protected:
    Transformation transformation;
    Material material;
};

class Sphere : public Surface
{
public:
    Sphere();
    Sphere(Transformation transformation, Material material);
    ~Sphere();

    Hit Intersect(Ray ray, float min, float max);
};
