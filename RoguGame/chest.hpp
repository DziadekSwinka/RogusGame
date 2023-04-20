#ifndef CHEST_HPP_INCLUDED
#define CHEST_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "equipment.hpp"
#include "character.hpp"

using namespace std;

class chest
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    static sf::Texture txt;
    static bool isLoaded;
    sf::Vector2i pos;
public:
    chest(sf::RenderWindow &window1,sf::Vector2f POS):window(window1),pos(POS)
    {
        if(!isLoaded)
        {
            txt.loadFromFile("Textures\\chest.png");
            isLoaded=true;
        }
        sprite.setTexture(txt);
        sprite.setPosition(POS);
    }
    void Update(character &P);
};

#endif // CHEST_HPP_INCLUDED
