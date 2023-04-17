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
    sf::Vector2f pos;
    double speed;
    double a,b;
    double DIR;
public:
    ammunition(sf::RenderWindow &window1,sf::Vector2f pos,float dir);
    void Update(sf::Vector2f Camera);
};

#endif // AMMUNITION_HPP_INCLUDED
