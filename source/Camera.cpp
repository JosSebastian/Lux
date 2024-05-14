#include "Camera.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

Camera::Camera()
    : resolution(glm::vec2(0.0f)), fov(glm::vec2(0.0f)), aspect(0.0f), transformation(Transformation()), matrix(glm::mat4(0.0f))
{
}

Camera::Camera(glm::vec2 resolution, float fov, Transformation transformation)
    : resolution(resolution), aspect(resolution.x / resolution.y), transformation(transformation)
{
    this->fov = glm::vec2(float(2 * atan(tan(fov / 2.0f) * aspect)), float(fov));
    this->matrix = glm::scale(glm::translate(glm::eulerAngleXYZ(transformation.rotate.x, transformation.rotate.y, transformation.rotate.z), transformation.translate), transformation.scale);
}

Camera::~Camera()
{
}