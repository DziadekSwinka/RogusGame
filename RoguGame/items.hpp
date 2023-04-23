#ifndef ITEMS_HPP_INCLUDED
#define ITEMS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "character.hpp"

const short numberOfItems=6;    //this same var in file equipment.hpp

struct
{
    sf::Texture txt[numberOfItems+3];
    /*sf::SoundBuffer SBF[numberOfSounds];
    sf::Sound sound;*/
}stat;

class item
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Clock clock;
    sf::Vector2i pos;
    /*std::string SoundsPath[numberOfSounds]=
    {   "360stopni.wav",
        "Gangaritus.wav"};*/

public:
    item(sf::RenderWindow &window1,short type):window(window1)
    {
        if(0>type || type>=numberOfItems)
            throw std::logic_error("Wrong type of item");
        if(type!=5)
        {
            sprite.setTexture(stat.txt[type]);
            sprite.setScale(0.2f,0.2f);
        }else
        {
            sprite.setTexture(stat.txt[type+std::rand()%4]);
            sprite.setScale(0.3f,0.3f);
        }
        sprite.setOrigin((stat.txt[type].getSize().x/2),(stat.txt[type].getSize().y/2));
        pos.x=(rand()%34700)+2500;
        pos.y=(rand()%34700)+2500;
        /*for(int i=0;i<numberOfSounds;i++)
            stat.SBF[i].loadFromFile("Sounds\\"+SoundsPath[i]);*/
    }
    item(sf::RenderWindow &window1,sf::Vector2f position,short type):window(window1),pos(position)
    {
        if(0>type || type>=numberOfItems)
            throw std::logic_error("Wrong type of item");
        if(type!=5)
        {
            sprite.setTexture(stat.txt[type]);
            sprite.setScale(0.2f,0.2f);
        }else
        {
            sprite.setTexture(stat.txt[type+std::rand()%4]);
            sprite.setScale(0.3f,0.3f);
        }
        sprite.setOrigin((stat.txt[type].getSize().x/2),(stat.txt[type].getSize().y/2));
    }
    ~item()
    {

    }
    bool Update(character &P);
};


#endif // ITEMS_HPP_INCLUDED
