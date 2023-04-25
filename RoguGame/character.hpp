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
    static bool ScaleX;
    int i;
    friend class item;
    friend class hand_weapon;
    hand_weapon *axe,*shovel,*sword;
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
        axe=new hand_weapon(window,"Textures\\axe.png",50);
        shovel=new hand_weapon(window,"Textures\\shovelHand.png",20);
        sword=new hand_weapon(window,"Textures\\sword.png",75);
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.6,0.6);
        sprite.setOrigin(400,700);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
        pickUp.setFont(GochiHand_Regular);
        pickUp.setString("Podnies [E]");
        pickUp.setFillColor(sf::Color::Magenta);
        pickUp.setCharacterSize(110);
        red_rect->setFillColor(sf::Color::Red);
        red_rect->setOutlineColor(sf::Color::Black);
        red_rect->setOutlineThickness(5);
        white_rect->setOutlineColor(sf::Color::Black);
        white_rect->setOutlineThickness(5);
        i=0;
    };
    void Update(sf::Vector2f veCam,double FTime);
};
#endif // CHARACTER_HPP_INCLUDED
