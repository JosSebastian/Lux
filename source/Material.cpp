#include "Material.hpp"

Material::Material()
{
}

Material::~Material()
{
}

glm::vec3 Material::Emissivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return glm::vec3(0.0f);
}

glm::vec3 Material::Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return glm::vec3(0.0f);
}

bool Material::Halt()
{
    return false;
}

Lambertian::Lambertian()
    : albedo(glm::vec3(1.0f))
{
}

Lambertian::Lambertian(glm::vec3 albedo)
    : albedo(albedo)
{
}

Lambertian::~Lambertian()
{
}

glm::vec3 Lambertian::Emissivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return glm::vec3(0.0f);
}

glm::vec3 Lambertian::Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return albedo / glm::pi<float>();
}

bool Lambertian::Halt()
{
    return false;
}

Light::Light()
    : radiance(glm::vec3(1.0f))
{
}

Light::Light(glm::vec3 radiance)
    : radiance(radiance)
{
}

Light::~Light()
{
}

glm::vec3 Light::Emissivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return radiance;
}

glm::vec3 Light::Reflectivity(Hit hit, glm::vec3 in, glm::vec3 out)
{
    return glm::vec3(0.0f);
}

bool Light::Halt()
{
    return true;
}
