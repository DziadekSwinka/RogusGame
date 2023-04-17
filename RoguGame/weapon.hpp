#ifndef WEAPON_HPP_INCLUDED
#define WEAPON_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "ammunition.hpp"

class weapon
{
public:
    weapon(sf::RenderWindow &window1);
    void Update(sf::Vector2f Center);
    std::vector<ammunition*>(ammo);
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    int fix;
};

#endif // WEAPON_HPP_INCLUDED
