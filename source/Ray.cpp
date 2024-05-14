#include "Ray.hpp"

#include <iostream>
#include <string>

Ray::Ray()
    : point(glm::vec3(0.0f)), direction(glm::vec3(0.0f))
{
}

Ray::Ray(const glm::vec3 &point, const glm::vec3 &direction)
    : point(point), direction(glm::normalize(direction))
{
}

Ray::~Ray()
{
}

void Ray::Log()
{
    std::cout << "point: " << "(" + std::to_string(point.x) + ", " + std::to_string(point.y) + ", " + std::to_string(point.z) + ")" << std::endl;
    std::cout << "direction: " << "(" + std::to_string(direction.x) + ", " + std::to_string(direction.y) + ", " + std::to_string(direction.z) + ")" << std::endl;
}

glm::vec3 Ray::At(float time)
{
    return point + time * direction;
}
