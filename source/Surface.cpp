#include "Surface.hpp"

Surface::Surface()
    : transformation(Transformation()), material(Material())
{
}

Surface::Surface(const Transformation &transformation, const Material &material)
    : transformation(transformation), material(material)
{
}

Surface::~Surface()
{
}

Sphere::Sphere()
    : Surface()
{
}

Sphere::Sphere(const Transformation &transformation, const Material &material)
    : Surface(transformation, material)
{
}

Sphere::~Sphere()
{
}

Hit Sphere::Intersect(const Ray &ray, float min, float max)
{
    float a = glm::dot(ray.direction, ray.direction);
    float b = 2.0f * glm::dot(ray.point - transformation.translate, ray.direction);
    float c = glm::dot(ray.point - transformation.translate, ray.point - transformation.translate) - glm::dot(transformation.scale, glm::vec3(1.0f / 3.0f)) * glm::dot(transformation.scale, glm::vec3(1.0f / 3.0f));

    Hit hit;
    float determinant = b * b - 4.0f * a * c;
    if (determinant > 0.0f)
    {
        float distance = glm::min((-b - sqrt(determinant)) / (2.0f * a), (-b + sqrt(determinant)) / (2.0f * a));
        if (distance > min && distance < max)
        {
            glm::vec3 position = ray.point + distance * ray.direction;
            glm::vec3 normal = glm::normalize((ray.point + distance * ray.direction - position) / glm::dot(transformation.scale, glm::vec3(1.0f / 3.0f)));

            hit = Hit(true, distance, position, normal, &material);
        }
    }

    return hit;
}
