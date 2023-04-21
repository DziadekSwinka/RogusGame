#include "items.hpp"

//bool item::isLoaded=false;

bool item::Update(character &P)
{
        if(abs(P.Center.x-pos.x)<250 && abs(P.Center.y-pos.y)<250)
        {
            P.showText=true;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                return true;
            }
        }
        sprite.setPosition(pos.x,pos.y);
        window.draw(sprite);
        return false;
    }
