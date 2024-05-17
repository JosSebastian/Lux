#include "Hit.hpp"

Hit::Hit()
    : hit(false), distance(0.0f), position(glm::vec3(0.0f)), normal(glm::vec3(0.0f)), material(Material())
{
}

Hit::Hit(bool hit, float distance, glm::vec3 position, glm::vec3 normal, Material material)
    : hit(hit), distance(distance), position(position), normal(normal), material(material)
{
}

Hit::~Hit()
{
}
