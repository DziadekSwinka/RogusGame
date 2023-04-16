#ifndef EQUIPMENT_HPP_INCLUDED
#define EQUIPMENT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

const short NumberOfItems=4;
//this same var in file items.hpp

class equipment
{
public:
    static unsigned int Stick;
    static unsigned int Stone;
    static unsigned int Flower1;
    static unsigned int Flower2;
    static unsigned int HP;
    static bool isLoaded;
    sf::RenderWindow &window;

    equipment(sf::RenderWindow &window1):window(window1)
    {
        backRect.setSize(sf::Vector2f(2516,600));
        backRect.setFillColor(sf::Color(80,80,80,200));
        backRect.setOutlineColor(sf::Color::Black);
        backRect.setOutlineThickness(6);
        backRect.setOrigin(1260,1);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");

        if(!isLoaded)
        {
            itemTexture[0].loadFromFile("Textures\\stone.png");
            itemTexture[1].loadFromFile("Textures\\stick.png");
            itemTexture[2].loadFromFile("Textures\\flower1.png");
            itemTexture[3].loadFromFile("Textures\\flower2.png");
            isLoaded=true;
        }

        for(int i=0;i<NumberOfItems;i++)
        {
            itemText[i].setFont(GochiHand_Regular);
            itemText[i].setColor(sf::Color::Red);
            itemText[i].setCharacterSize(140);
            itemSprite[i].setTexture(itemTexture[i]);
            itemSprite[i].setScale(0.1,0.1);
            itemSprite[i].setOrigin(itemTexture[i].getSize().x/2.f,itemTexture[i].getSize().y/2.f);
        }
    }
    void Update(sf::Vector2f pos);
private:
    sf::Font GochiHand_Regular;
    sf::RectangleShape backRect;
    sf::Text itemText[NumberOfItems];
    sf::Texture itemTexture[NumberOfItems];
    sf::Sprite itemSprite[NumberOfItems];
};

#endif // EQUIPMENT_HPP_INCLUDED
