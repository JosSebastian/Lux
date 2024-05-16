#include "Camera.hpp"

Camera::Camera()
    : resolution(glm::vec2(0.0f)), fov(glm::vec2(0.0f)), aspect(0.0f), transformation(Transformation()), matrix(glm::mat4(0.0f))
{
}

Camera::Camera(const glm::vec2 &resolution, float fov, const Transformation &transformation)
    : resolution(resolution), aspect(resolution.x / resolution.y), transformation(transformation)
{
    this->fov = glm::vec2(float(2 * atan(tan(fov / 2.0f) * aspect)), float(fov));
    this->matrix = glm::scale(glm::translate(glm::eulerAngleXYZ(transformation.rotate.x, transformation.rotate.y, transformation.rotate.z), transformation.translate), transformation.scale);
}

Camera::~Camera()
{
}

void Camera::Log()
{
    std::cout << "resolution: " << "(" + std::to_string(resolution.x) + ", " + std::to_string(resolution.y) + ")" << std::endl;
    std::cout << "fov: " << "(" + std::to_string(fov.x) + ", " + std::to_string(fov.y) + ")" << std::endl;
    std::cout << "aspect ratio: " << "(" + std::to_string(aspect) + ")" << std::endl;

    transformation.Log();
}

Ray Camera::CreateRay(const glm::vec2 &pixel)
{

    glm::vec2 coordinate = glm::vec2((pixel.x + 0.5f) / resolution.x * aspect, (pixel.y + 0.5f) / resolution.y) * 2.0f - 1.0f;
    coordinate *= glm::vec2(tan(fov.x / 2.0f), tan(fov.y / 2.0f));

    glm::vec3 point = matrix * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec3 direction = matrix * glm::normalize(glm::vec4(coordinate, -1.0f, 0.0f));

    return Ray(point, direction);
}
