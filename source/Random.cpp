#include "Random.hpp"

Random::Random()
    : distribution(0.0f, 1.0f)
{
    std::random_device random;
    generator = std::mt19937_64(random());
}

Random::Random(unsigned long seed)
    : generator(seed), distribution(0.0f, 1.0f)
{
}

Random::~Random()
{
}

float Random::CreateRandom()
{
    return distribution(generator);
}

glm::vec3 Random::CreateSphere()
{
    glm::vec3 random;
    do
    {
        random = glm::vec3(2.0f * CreateRandom() - 1.0f, 2.0f * CreateRandom() - 1.0f, 2.0f * CreateRandom() - 1.0f);
    } while (dot(random, random) >= 1.0f);

    return glm::normalize(random);
}

glm::vec3 Random::CreateHemisphere(glm::vec3 normal)
{
    glm::vec3 random;
    do
    {
        random = glm::vec3(2.0f * CreateRandom() - 1.0f, 2.0f * CreateRandom() - 1.0f, 2.0f * CreateRandom() - 1.0f);
    } while (dot(random, random) >= 1.0f);

    if (dot(random, normal) > 0.0f)
        random = random;
    else
        random = -random;

    return glm::normalize(random);
}