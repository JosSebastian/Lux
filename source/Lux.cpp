#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <chrono>

#include "Scene.hpp"
#include "Camera.hpp"

int main(int argc, char const *argv[])
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    try
    {
        std::shared_ptr<Camera> camera = std::make_shared<Camera>(512, 512, glm::radians(60.0f), Transform(glm::vec3(0.0f, 3.0f, 0.0f), glm::radians(glm::vec3(-30.0f, 0.0f, 0.0f)), glm::vec3(1.0f)));
        std::vector<std::shared_ptr<Shape>> shapes;

        std::shared_ptr<Light> top_material = std::make_shared<Light>(glm::vec3(1.0f));
        std::shared_ptr<Sphere> top = std::make_shared<Sphere>(Transform(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(0.0f), glm::vec3(50.0f)), top_material);
        shapes.push_back(top);

        std::shared_ptr<Lambertian> left_material = std::make_shared<Lambertian>(glm::vec3(1.0f, 0.2f, 0.2f));
        std::shared_ptr<Sphere> left = std::make_shared<Sphere>(Transform(glm::vec3(-1.025f, 0.55f, -5.0f), glm::vec3(0.0f), glm::vec3(1.0f)), left_material);
        shapes.push_back(left);

        std::shared_ptr<Lambertian> right_material = std::make_shared<Lambertian>(glm::vec3(0.2f, 1.0f, 0.2f));
        std::shared_ptr<Sphere> right = std::make_shared<Sphere>(Transform(glm::vec3(1.025f, 0.55f, -5.0f), glm::vec3(0.0f), glm::vec3(1.0f)), right_material);
        shapes.push_back(right);

        std::shared_ptr<Material> bottom_material = std::make_shared<Lambertian>(glm::vec3(0.5f));
        std::shared_ptr<Sphere> bottom = std::make_shared<Sphere>(Transform(glm::vec3(0.0f, -100.0f, -5.0f), glm::vec3(0.0f), glm::vec3(99.5f)), bottom_material);
        shapes.push_back(bottom);

        std::shared_ptr<Image> image = std::make_shared<Image>(512, 512, "image.png");

        auto scene = Scene(camera, shapes);
        scene.Render(image, 512);
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Time: " << duration.count() << "s\n";
    return EXIT_SUCCESS;
}
