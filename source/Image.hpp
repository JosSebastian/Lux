#pragma once

#include "Support.hpp"

class Image
{
public:
    Image();
    Image(int width, int height, const std::string &file);
    ~Image();

    void Pixel(int x, int y, glm::vec3 color);
    void Render();

private:
    int width;
    int height;

    int channels;
    std::vector<float> pixels;

    std::string file;
};
