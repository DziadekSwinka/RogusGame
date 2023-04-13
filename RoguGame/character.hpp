#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include<SFML/Graphics.hpp>

#include "equipment.hpp"

class character
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    sf::Clock clock;
    sf::Font GochiHand_Regular;
    sf::Text pickUp;
    sf::Vector2f Center;
    equipment *equip;
    bool showText;
    int i;
    friend class item;

public:
    character(sf::RenderWindow &window1,std::string path):window(window1)
    {
        equip=new equipment(window);
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.6,0.6);
        sprite.setOrigin(400,700);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
        pickUp.setFont(GochiHand_Regular);
        pickUp.setString("Podnies [E]");
        pickUp.setColor(sf::Color::Magenta);
        pickUp.setCharacterSize(110);
        i=0;
    };
    void Update(sf::Vector2f veCam)
    {
        Center=veCam;
        sprite.setPosition(Center);
        pickUp.setPosition(Center.x-220,Center.y-600);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                if(-sprite.getScale().x<0)
                    sprite.setScale(-sprite.getScale().x,sprite.getScale().y);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                if(-sprite.getScale().x>0)
                    sprite.setScale(-sprite.getScale().x,sprite.getScale().y);

            if(clock.getElapsedTime().asSeconds()>=0.2)
            {
                i++;
                if(i>2)
                    i=0;
                clock.restart();
            }
            sprite.setTextureRect(sf::IntRect(800*i,0,800,1400));
        }else
        {
            i=0;
            sprite.setTextureRect(sf::IntRect(2400,0,800,1400));
        }
        window.draw(sprite);
        if(showText)
            window.draw(pickUp);
        showText=false;
    }
};


#endif // CHARACTER_HPP_INCLUDED
