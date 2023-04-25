#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <map>


const short NumberOfItems=6;
//this same var in file items.hpp

class equipment
{
public:
    static unsigned int Stick;
    static unsigned int Stone;
    static unsigned int Flower1;
    static unsigned int Flower2;
    static unsigned int Plastic;
    static unsigned int Ore;
    static unsigned int HP;
    static unsigned int Bullets;
    static bool Gun;
    static bool Axe;
    static bool Shovel;
    static bool Sword;
    static bool isLoaded;
    static int hand;
    sf::RenderWindow &window;
    std::map<int,bool*>items;

    equipment(sf::RenderWindow &window1):window(window1)
    {
        items[2]=&Gun;
        items[3]=&Axe;
        items[4]=&Shovel;
        items[5]=&Sword;
        backRect.setSize(sf::Vector2f(2516,600));
        backRect.setFillColor(sf::Color(80,80,80,220));
        backRect.setOutlineColor(sf::Color::Black);
        backRect.setOutlineThickness(6);
        backRect.setOrigin(1260,1);
        headShape.setSize(sf::Vector2f(2516,180));
        headShape.setFillColor(sf::Color(100,100,100,255));
        headShape.setOutlineColor(sf::Color::Black);
        headShape.setOutlineThickness(6);
        headShape.setOrigin(1260,1);
        headCenter.setSize(sf::Vector2f(516,250));
        headCenter.setFillColor(sf::Color(100,100,100,255));
        headCenter.setOutlineColor(sf::Color::Black);
        headCenter.setOutlineThickness(6);
        headCenter.setOrigin(1260,1);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");

        if(!isLoaded)
        {
            itemTexture[0].loadFromFile("Textures\\stone.png");
            itemTexture[1].loadFromFile("Textures\\stick.png");
            itemTexture[2].loadFromFile("Textures\\flower1.png");
            itemTexture[3].loadFromFile("Textures\\flower2.png");
            itemTexture[4].loadFromFile("Textures\\ore.png");
            itemTexture[5].loadFromFile("Textures\\plastic3.png");
            headIc[0].loadFromFile("Textures\\bullet.png");
            headIc[1].loadFromFile("Textures\\Gun.png");
            headIc[2].loadFromFile("Textures\\beer.png");
            headIc[3].loadFromFile("Textures\\axe.png");
            headIc[4].loadFromFile("Textures\\shovel.png");
            headIc[5].loadFromFile("Textures\\sword.png");
            isLoaded=true;
        }
        ammo.setFont(GochiHand_Regular);
        ammo.setFillColor(sf::Color::Red);
        ammo.setCharacterSize(140);
        for(int i=0;i<NumberOfItems;i++)
        {
            itemText[i].setFont(GochiHand_Regular);
            itemText[i].setFillColor(sf::Color::Red);
            itemText[i].setCharacterSize(140);
            itemSprite[i].setTexture(itemTexture[i]);
            itemSprite[i].setScale(0.1,0.1);
            if(i==5)
                itemSprite[i].setScale(0.2,0.2);
            itemSprite[i].setOrigin(itemTexture[i].getSize().x/2.f,itemTexture[i].getSize().y/2.f);
        }
        for(int i=0;i<6;i++)
        {
            if(i<5)
            {
                headIcon[i].setTexture(headIc[i]);
                headText[i].setFont(GochiHand_Regular);
                headText[i].setFillColor(sf::Color::Red);
                headText[i].setCharacterSize(100);
                headText[i].setString("["+std::to_string(i)+"]");
            }
            switch(i)
            {
            case 1:
                headIcon[i].setScale(0.25,0.25);
                break;
            case 2:
                {
                    headIcon[i].setScale(0.4,0.35);
                    break;
                }
            case 3:
                {
                    headIcon[i].setRotation(90);
                    headIcon[i].setScale(0.35,0.25);
                    break;
                }
            case 4:
                {
                    headIcon[i].setRotation(90);
                    headIcon[i].setScale(0.48,0.25);
                    break;
                }
            default:
                headIcon[i].setScale(0.4,0.4);
                break;
            }
        }
        headIcon[1].setOrigin(1700,-50);
    }
    void Update(sf::Vector2f pos);
private:
    sf::Font GochiHand_Regular;
    sf::RectangleShape backRect,headShape,headCenter;
    sf::Text itemText[NumberOfItems],ammo,headText[6];
    sf::Texture itemTexture[NumberOfItems],headIc[5];
    sf::Sprite itemSprite[NumberOfItems],headIcon[6];
};

#endif // EQUIPMENT_HPP_INCLUDED
