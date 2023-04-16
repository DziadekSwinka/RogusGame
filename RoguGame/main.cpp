#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "Application.hpp"

int main(int argc, char *argv[])
{
    try
    {
        Application();
    }catch(...)
    {
        std::cout<<"Error"<<std::endl;
        std::_Exit(0);
    }
    return 0;
}
