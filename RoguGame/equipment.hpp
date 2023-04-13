#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class equipment
{
public:
    unsigned int stick;
    unsigned int rock;
    unsigned int flower1;
    unsigned int flower2;
    sf::RenderWindow &window;
    equipment(sf::RenderWindow &window1):window(window1)
    {
        stick=0;
        rock=0;
        flower1=0;
        flower2=0;
    }
};

#endif // EQUIPMENT_HPP_INCLUDED
