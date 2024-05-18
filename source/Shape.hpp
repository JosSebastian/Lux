#pragma once

#include "Ray.hpp"
#include "Hit.hpp"
#include "Material.hpp"

class Shape
{
public:
    Shape();
    Shape(Transform transform, std::shared_ptr<Material> material);
    ~Shape();

    virtual Hit Intersect(Ray ray, float min, float max) = 0;

protected:
    Transform transform;
    std::shared_ptr<Material> material;
};

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(Transform transform, std::shared_ptr<Material> material);
    ~Sphere();

    Hit Intersect(Ray ray, float min, float max);
};
