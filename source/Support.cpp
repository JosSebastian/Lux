#include "Support.hpp"

Transform::Transform()
    : translate(glm::vec3(0.0f)), rotate(glm::vec3(0.0f)), scale(glm::vec3(1.0f))
{
}

Transform::Transform(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
    : translate(translate), rotate(rotate), scale(scale)
{
}

Transform::~Transform()
{
}
