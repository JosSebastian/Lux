#include "Camera.hpp"

Camera::Camera()
    : width(width), height(height), fov(glm::vec2(0.0f)), aspect(0.0f), transform(Transform()), matrix(glm::mat4(0.0f))
{
}

Camera::Camera(int width, int height, float fov, Transform transform)
    : width(width), height(height), aspect(float(width) / float(height)), transform(transform)
{
    this->fov = glm::vec2(float(2 * atan(tan(fov / 2.0f) * aspect)), float(fov));
    this->matrix = glm::scale(glm::translate(glm::eulerAngleXYZ(transform.rotate.x, transform.rotate.y, transform.rotate.z), transform.translate), transform.scale);
}

Camera::~Camera()
{
}

Ray Camera::CreateRay(int x, int y)
{

    glm::vec2 coordinate = glm::vec2((x + 0.5f) / width * aspect, (y + 0.5f) / height) * 2.0f - 1.0f;
    coordinate *= glm::vec2(tan(fov.x / 2.0f), tan(fov.y / 2.0f));

    glm::vec3 point = matrix * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    glm::vec3 direction = matrix * glm::normalize(glm::vec4(coordinate, -1.0f, 0.0f));

    return Ray(point, direction);
}
