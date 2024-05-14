#include "Support.hpp"

#include <iostream>
#include <string>

Transformation::Transformation()
    : translate(glm::vec3(0.0f)), rotate(glm::vec3(0.0f)), scale(glm::vec3(1.0f))
{
}

Transformation::Transformation(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
    : translate(translate), rotate(rotate), scale(scale)
{
}

Transformation::~Transformation()
{
}

void Transformation::Log()
{
    std::cout << "translate: " << "(" + std::to_string(translate.x) + ", " + std::to_string(translate.y) + ", " + std::to_string(translate.z) + ")" << std::endl;
    std::cout << "rotate: " << "(" + std::to_string(rotate.x) + ", " + std::to_string(rotate.y) + ", " + std::to_string(rotate.z) + ")" << std::endl;
    std::cout << "scale: " << "(" + std::to_string(scale.x) + ", " + std::to_string(scale.y) + ", " + std::to_string(scale.z) + ")" << std::endl;
}