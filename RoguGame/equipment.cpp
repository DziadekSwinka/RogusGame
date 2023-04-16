#include "equipment.hpp"
#include "Enemy.hpp"

unsigned int equipment::Stick=0;
unsigned int equipment::Stone=0;
unsigned int equipment::Flower1=0;
unsigned int equipment::Flower2=0;
unsigned int equipment::HP=100;
bool equipment::isLoaded=false;

void equipment::Update(sf::Vector2f pos)
{
    itemText[0].setString(std::to_string(Stick));
    itemText[1].setString(std::to_string(Stone));
    itemText[2].setString(std::to_string(Flower1));
    itemText[3].setString(std::to_string(Flower2));
    backRect.setPosition(pos.x,pos.y+1600);
    window.draw(backRect);
    for(int i=0;i<NumberOfItems;i++)
    {
        //itemText[i].setOrigin(itemText[i].getCharacterSize()/2,0);
        itemText[i].setPosition((pos.x-600)+(i*400),pos.y+1950);
        itemSprite[i].setPosition((pos.x-600)+(i*400),pos.y+1750);
        window.draw(itemText[i]);
        window.draw(itemSprite[i]);
    }
}
