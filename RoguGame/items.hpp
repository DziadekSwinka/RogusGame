#ifndef ITEMS_HPP_INCLUDED
#define ITEMS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "character.hpp"

const short numberOfItems=4;
//this same var in file equipment.hpp

struct
{
    sf::Texture txt[4];
}stat;

class item
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Clock clock;
    sf::Vector2i pos;
public:
    item(sf::RenderWindow &window1,short type):window(window1)
    {
        if(0>type || type>=numberOfItems)
            throw std::logic_error("Wrong type of item");
        sprite.setTexture(stat.txt[type]);
        sprite.setScale(0.2f,0.2f);
        sprite.setOrigin((stat.txt[type].getSize().x/2),(stat.txt[type].getSize().y/2));
        pos.x=(rand()%34700)+2500;
        pos.y=(rand()%34700)+2500;
    }
    bool Update(character &P);
};


#endif // ITEMS_HPP_INCLUDED
