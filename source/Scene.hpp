#pragma once

#include "Support.hpp"
#include "Random.hpp"
#include "Camera.hpp"
#include "Shape.hpp"
#include "Image.hpp"

class Scene
{
public:
    Scene();
    Scene(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shape>> shapes);
    ~Scene();

    Hit Intersect(Ray ray);
    glm::vec3 Sample(Ray ray);
    void Render(std::shared_ptr<Image> image, int samples);

private:
    std::shared_ptr<Camera> camera;
    std::vector<std::shared_ptr<Shape>> shapes;
};
