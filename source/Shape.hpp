#pragma once

#include "Ray.hpp"
#include "Hit.hpp"
#include "Material.hpp"

class Shape
{
public:
    Shape();
    Shape(Transformation transformation, Material material);
    ~Shape();

    virtual Hit Intersect(Ray ray, float min, float max) = 0;

protected:
    Transformation transformation;
    Material material;
};

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(Transformation transformation, Material material);
    ~Sphere();

    Hit Intersect(Ray ray, float min, float max);
};
