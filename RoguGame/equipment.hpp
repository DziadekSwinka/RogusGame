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
    sf::RenderWindow &window;
    equipment(sf::RenderWindow &window1):window(window1)
    {
        backRect.setSize(sf::Vector2f(2516,500));
        backRect.setFillColor(sf::Color(80,80,80,200));
        backRect.setOutlineColor(sf::Color::Black);
        backRect.setOutlineThickness(4);
        backRect.setOrigin(1260,1);
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
        for(int i=0;i<NumberOfItems;i++)
        {
            itemText[i].setFont(GochiHand_Regular);
            itemText[i].setColor(sf::Color::Red);
            itemText[i].setCharacterSize(140);
        }

    }
    void Update(sf::Vector2f pos);
private:
    sf::Font GochiHand_Regular;
    sf::RectangleShape backRect;
    sf::Text itemText[NumberOfItems];
};

#endif // EQUIPMENT_HPP_INCLUDED
