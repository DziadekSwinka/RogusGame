#include "equipment.hpp"
#include "Enemy.hpp"

unsigned int equipment::Stick=0;
unsigned int equipment::Stone=0;
unsigned int equipment::Flower1=0;
unsigned int equipment::Flower2=0;
unsigned int equipment::Ore=0;
unsigned int equipment::HP=100;
unsigned int equipment::Bullets=12;
bool equipment::Gun=true;
bool equipment::isLoaded=false;

void equipment::Update(sf::Vector2f pos)
{
    itemText[0].setString(std::to_string(Stone));
    itemText[1].setString(std::to_string(Stick));
    itemText[2].setString(std::to_string(Flower1));
    itemText[3].setString(std::to_string(Flower2));
    itemText[4].setString(std::to_string(Ore));
    backRect.setPosition(pos.x,pos.y+1600);
    headShape.setPosition(pos.x,pos.y-2500);
    headCenter.setPosition(pos.x+1000,pos.y-2500);
    ammo.setPosition(pos.x-1200,pos.y-2510);
    ammo.setString(std::to_string(Bullets));
    window.draw(backRect);
    window.draw(headShape);
    window.draw(headCenter);
    window.draw(ammo);
    for(int i=0;i<2;i++)
    {
        headIcon[i].setPosition(pos.x-1050+i*600,pos.y-2510);
        window.draw(headIcon[i]);
    }
    if(!Gun)
        headIcon[1].setColor(sf::Color(225,225,225,128));
    else
        headIcon[1].setColor(sf::Color(255,255,255,255));
    for(int i=0;i<NumberOfItems;i++)
    {
        //itemText[i].setOrigin(itemText[i].getCharacterSize()/2,0);
        itemText[i].setPosition((pos.x-600)+(i*400),pos.y+1950);
        itemSprite[i].setPosition((pos.x-600)+(i*400),pos.y+1750);
        window.draw(itemText[i]);
        window.draw(itemSprite[i]);
    }
}
