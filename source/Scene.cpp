#include "Scene.hpp"

Scene::Scene()
{
}

Scene::Scene(std::shared_ptr<Camera> camera, std::vector<std::shared_ptr<Shape>> shapes)
    : camera(camera), shapes(shapes)
{
}

Scene::~Scene()
{
}

Hit Scene::Intersect(Ray ray)
{
    Hit hit;
    hit.distance = INFINITY;

    for (int s = 0; s < shapes.size(); s++)
    {
        Hit candidate = shapes.at(s)->Intersect(ray, 0.01f, INFINITY);
        if (candidate.hit && candidate.distance < hit.distance)
        {
            hit = candidate;
        }
    }

    return hit;
}

glm::vec3 Scene::Sample(Ray ray)
{
    const int paths = 16;

    glm::vec3 radiance(0.0f);
    glm::vec3 flux(1.0f);

    Random random;
    for (int p = 0; p < paths; p++)
    {
        Hit hit = Intersect(ray);
        if (!hit.hit)
            break;

        glm::vec3 direction = random.CreateHemisphere(hit.normal);

        glm::vec3 in = -direction;
        glm::vec3 out = -ray.direction;

        radiance += flux * hit.material->Emissivity(hit, in, out);

        if (hit.material->Halt())
            break;

        flux *= hit.material->Reflectivity(hit, in, out) * glm::dot(hit.normal, direction) * 2.0f * glm::pi<float>();

        ray = Ray(hit.position, direction);
    }

    return radiance;
}

void Scene::Render(std::shared_ptr<Image> image, int samples)
{
#pragma omp parallel for
    for (int x = 0; x < image->width; x++)
    {
        for (int y = 0; y < image->height; y++)
        {
            glm::vec3 color(0.0f);
            for (int s = 0; s < samples; s++)
            {
                Ray ray = camera->CreateRay(x, y);
                color += Sample(ray);
            }
            color /= samples;

            image->Pixel(x, y, color);
        }
    }

    image->Render();
}
