#pragma once

#include "Support.hpp"
#include "Camera.hpp"
#include "Shape.hpp"
#include "Image.hpp"

class Scene
{
public:
    Scene();
    ~Scene();

    void Render(std::shared_ptr<Image> image);

private:
    std::shared_ptr<Camera> camera;
    std::vector<std::shared_ptr<Shape>> shapes;
};
