#include <cstdlib>
#include <stdexcept>
#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
    }
    catch (const std::exception &exception)
    {
        std::cerr << exception.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
