#include "Image.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/image_write.h>

Image::Image()
    : width(0), height(0), channels(3), pixels(0), file("")
{
}

Image::Image(int width, int height, std::string file)
    : width(width), height(height), channels(3), pixels(width * height * channels), file(file)
{
}

Image::~Image()
{
}

void Image::Pixel(int x, int y, glm::vec3 color)
{
    int index = (height - y - 1) * width + x;

    assert(index >= 0);
    assert(3 * index + 2 < (int)pixels.size());

    pixels.at(3 * index + 0) = color.r;
    pixels.at(3 * index + 1) = color.g;
    pixels.at(3 * index + 2) = color.b;
}

void Image::Render()
{
    std::vector<unsigned char> colors(pixels.size());
    for (int c = 0; c < pixels.size(); c++)
    {
        colors.at(c) = static_cast<unsigned char>(pixels.at(c) * 255);
    }

    int stride = width * channels * sizeof(unsigned char);
    int result = stbi_write_png(file.c_str(), width, height, channels, &colors[0], stride);
}
