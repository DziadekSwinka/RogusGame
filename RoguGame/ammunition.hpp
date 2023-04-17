#ifndef AMMUNITION_HPP_INCLUDED
#define AMMUNITION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

class ammunition
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    double speed;
    double a,b;
    double DIR;
public:
    sf::Vector2f pos;
    ammunition(sf::RenderWindow &window1,sf::Vector2f pos,float dir);
    bool Update(sf::Vector2f Camera);
};

#endif // AMMUNITION_HPP_INCLUDED
