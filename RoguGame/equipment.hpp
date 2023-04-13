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
        backRect.setSize(sf::Vector2f(2516,500));
        backRect.setFillColor(sf::Color(80,80,80,200));
        backRect.setOutlineColor(sf::Color::Black);
        backRect.setOutlineThickness(4);
        backRect.setOrigin(1260,1);
    }
    void Update(sf::Vector2f pos);
private:
    sf::RectangleShape backRect;
};

#endif // EQUIPMENT_HPP_INCLUDED
