#pragma once

#include "Support.hpp"

class Image
{
public:
    int width;
    int height;

    Image();
    Image(int width, int height, std::string file);
    ~Image();

    void Pixel(int x, int y, glm::vec3 color);
    void Render();

private:
    int channels;
    std::vector<float> pixels;

    std::string file;
};
