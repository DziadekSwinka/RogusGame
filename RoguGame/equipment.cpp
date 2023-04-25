#include "equipment.hpp"
#include "Enemy.hpp"

unsigned int equipment::Stick=0;
unsigned int equipment::Stone=0;
unsigned int equipment::Flower1=0;
unsigned int equipment::Flower2=0;
unsigned int equipment::Plastic=0;
unsigned int equipment::Ore=0;
unsigned int equipment::HP=100;
unsigned int equipment::Bullets=12;
int equipment::hand=0;
bool equipment::Gun=false;
bool equipment::Axe=true;
bool equipment::Shovel=true;
bool equipment::Sword=false;
bool equipment::isLoaded=false;

void equipment::Update(sf::Vector2f pos)
{
    itemText[0].setString(std::to_string(Stone));
    itemText[1].setString(std::to_string(Stick));
    itemText[2].setString(std::to_string(Flower1));
    itemText[3].setString(std::to_string(Flower2));
    itemText[4].setString(std::to_string(Ore));
    itemText[5].setString(std::to_string(Plastic));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && Gun){
        hand=2;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        /////////////////////////////////////////////////////////////////////////////////
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && Axe){
        hand=3;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && Shovel){
        hand=4;}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)){
        hand=0;}
    backRect.setPosition(pos.x,pos.y+1600);
    headShape.setPosition(pos.x,pos.y-2500);
    headCenter.setPosition(pos.x+1000,pos.y-2500);
    ammo.setPosition(pos.x-1200,pos.y-2510);
    ammo.setString(std::to_string(Bullets));
    window.draw(backRect);
    window.draw(headShape);
    window.draw(headCenter);
    window.draw(ammo);
    for(int i=1;i<5;i++)
    {
        if(i<2)
        {
            headIcon[i].setPosition(pos.x-1050+i*600,pos.y-2510);
            headText[i].setPosition(pos.x-1350+i*600,pos.y-2350);
        }
        else
        {
            headIcon[i].setPosition(pos.x-350+i*350,pos.y-2510);
            headText[i].setPosition(pos.x-300+i*310,pos.y-2350);
        }
        if(hand==i)
            headText[i].setFillColor(sf::Color::Blue);
        else
        headText[i].setFillColor(sf::Color::Red);
        window.draw(headIcon[i]);
        window.draw(headText[i+1]);
    }
    for(int i=1;i<5;i++)
    {
        if(*items[i+1]!=0)
            headIcon[i].setColor(sf::Color(225,225,225,255));
        else
            headIcon[i].setColor(sf::Color(255,255,255,128));
    }
    for(int i=0;i<NumberOfItems;i++)
    {
        //itemText[i].setOrigin(itemText[i].getCharacterSize()/2,0);
        itemText[i].setPosition((pos.x-1000)+(i*400),pos.y+1950);
        itemSprite[i].setPosition((pos.x-1000)+(i*400),pos.y+1750);
        window.draw(itemText[i]);
        window.draw(itemSprite[i]);
    }
}
