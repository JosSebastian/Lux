#include "Ray.hpp"

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

glm::vec3 Ray::At(float time)
{
    return point + time * direction;
}
