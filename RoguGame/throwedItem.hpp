#ifndef THROWEDITEM_HPP_INCLUDED
#define THROWEDITEM_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <cmath>

class ThrowedItem
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Vector2f pos;
    float rotationRate;
    double a,b,c;
    std::string path[5]=   {"banany.png",
                            "kij.png",
                            "mlotek.png",
                            "rower.png",
                            "krzeslo.png"};
public:
    ThrowedItem(sf::RenderWindow &window1,sf::Vector2f startPos,double alpha);
    bool Update(sf::Vector2f charpos);
};

#endif // THROWEDITEM_HPP_INCLUDED
