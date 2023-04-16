#include "items.hpp"

int item::PlayingNumber=0;
//bool item::isLoaded=false;
using std::cout;
using std::endl;

bool item::Update(character &P)
{
        if(PlayingNumber>0)
        {

        }
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
