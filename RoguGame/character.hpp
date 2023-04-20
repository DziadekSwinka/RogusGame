#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "equipment.hpp"
#include "crafting.hpp"
#include "weapon.hpp"

class character
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    sf::Clock clock;
    sf::Font GochiHand_Regular;
    sf::Text pickUp;
    sf::Vector2f Center,Rsize;
    sf::RectangleShape *red_rect,*white_rect;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    equipment *equip;
    weapon *gun;
    bool showText;
    int i;
    friend class item;

public:
    unsigned int HP;
    character(sf::RenderWindow &window1,std::string path):window(window1)
    {
        buffer.loadFromFile("Sounds\\steps.wav");
        sound.setBuffer(buffer);
        sound.setLoop(true);
        sound.setVolume(40);
        equip=new equipment(window);
        red_rect=new sf::RectangleShape(sf::Vector2f(500,50));
        white_rect=new sf::RectangleShape(sf::Vector2f(500,50));
        gun=new weapon(window);
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.6,0.6);
        sprite.setOrigin(400,700);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
        pickUp.setFont(GochiHand_Regular);
        pickUp.setString("Podnies [E]");
        pickUp.setColor(sf::Color::Magenta);
        pickUp.setCharacterSize(110);
        red_rect->setFillColor(sf::Color::Red);
        red_rect->setOutlineColor(sf::Color::Black);
        red_rect->setOutlineThickness(5);
        white_rect->setOutlineColor(sf::Color::Black);
        white_rect->setOutlineThickness(5);
        i=0;
    };
    void Update(sf::Vector2f veCam)
    {
        Center=veCam;
        HP=equip->HP;
        sprite.setPosition(Center);
        pickUp.setPosition(Center.x-250,Center.y-800);
        red_rect->setPosition(Center.x-250,Center.y-600);
        white_rect->setPosition(Center.x-250,Center.y-600);
        if(!crafting::showInterface)
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if(sound.getStatus()!=sf::Sound::Playing)
                    sound.play();
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
                if(!crafting::showInterface && HP>0)
                    sprite.setTextureRect(sf::IntRect(800*i,0,800,1400));
            }else
            {
                sound.stop();
                i=0;
                sprite.setTextureRect(sf::IntRect(2400,0,800,1400));
                if(HP<=0)
                {
                    sprite.setTextureRect(sf::IntRect(800*4,0,800,1400));
                }
            }
        Rsize=sf::Vector2f(HP*5,red_rect->getSize().y);
        red_rect->setSize(Rsize);
        window.draw(sprite);
        if(equipment::Gun)
        gun->Update(veCam);
        if(HP>0)
        {
            window.draw(*white_rect);
            window.draw(*red_rect);
            if(showText)
                window.draw(pickUp);
        }
        showText=false;
        if(!crafting::showInterface)
            equip->Update(sprite.getPosition());
    }
};


#endif // CHARACTER_HPP_INCLUDED
