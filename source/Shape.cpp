#include "Shape.hpp"

Shape::Shape()
    : transform(Transform())
{
}

Shape::Shape(Transform transform, std::shared_ptr<Material> material)
    : transform(transform), material(material)
{
}

Shape::~Shape()
{
}

Sphere::Sphere()
    : Shape()
{
}

Sphere::Sphere(Transform transform, std::shared_ptr<Material> material)
    : Shape(transform, material)
{
}

Sphere::~Sphere()
{
}

Hit Sphere::Intersect(Ray ray, float min, float max)
{
    float a = glm::dot(ray.direction, ray.direction);
    float b = 2.0f * glm::dot(ray.point - transform.translate, ray.direction);
    float c = glm::dot(ray.point - transform.translate, ray.point - transform.translate) - glm::dot(transform.scale, glm::vec3(1.0f / 3.0f)) * glm::dot(transform.scale, glm::vec3(1.0f / 3.0f));

    Hit hit;
    float determinant = b * b - 4.0f * a * c;
    if (determinant > 0.0f)
    {
        float distance;

        distance = glm::min((-b - sqrt(determinant)) / (2.0f * a), (-b + sqrt(determinant)) / (2.0f * a));
        if (distance > min && distance < max)
        {
            glm::vec3 position = ray.point + distance * ray.direction;
            glm::vec3 normal = glm::normalize((position - transform.translate) / dot(transform.scale, glm::vec3(1.0f / 3.0f)));

            hit = Hit(true, distance, position, normal, material);
            return hit;
        }

        distance = glm::max((-b - sqrt(determinant)) / (2.0f * a), (-b + sqrt(determinant)) / (2.0f * a));
        if (distance > min && distance < max)
        {
            glm::vec3 position = ray.point + distance * ray.direction;
            glm::vec3 normal = glm::normalize((position - transform.translate) / dot(transform.scale, glm::vec3(1.0f / 3.0f)));

            hit = Hit(true, distance, position, normal, material);
            return hit;
        }
    }

    return hit;
}
