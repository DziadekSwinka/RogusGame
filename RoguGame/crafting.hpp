#ifndef CRAFTING_HPP_INCLUDED
#define CRAFTING_HPP_INCLUDED

#include <SFML/Graphics.hpp>
//#include <iostream>

#include "recipe.hpp"

//using namespace std;

class line
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt1,txt2;
    sf::Vector2f pos;
    sf::Text text[6];
    sf::Font GochiHand_Regular;
public:
    line(sf::RenderWindow &window1,float posX,float posY):window(window1)
    {
        pos=sf::Vector2f(posX,posY);
        txt1.loadFromFile("Textures\\GUI\\wytworz1.png");
        txt2.loadFromFile("Textures\\GUI\\wytworz2.png");
        GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
        for(int i=0;i<6;i++)
        {
            text[i].setFont(GochiHand_Regular);
            text[i].setColor(sf::Color::Red);
            text[i].setCharacterSize(110);
        }

    }
    void Update(sf::Vector2f DIM, int i)
    {
        sprite.setPosition(DIM.x+pos.x,DIM.y+pos.y);
        for(int j=0;j<5;j++)    //without no.5 element
        {
            text[j].setPosition(DIM.x+pos.x-400-200*j,DIM.y+pos.y+50);
            text[j].setString(std::to_string(recipe.ingr[i][j]));
        }
        text[5].setString(recipe.name[i]);
        text[5].setPosition(DIM.x+pos.x-400-1800,DIM.y+pos.y+50);

        sf::Vector2i mouse=sf::Mouse::getPosition();
        sf::Vector2f button=sprite.getPosition();
        if(mouse.x<pos.x+250 && mouse.x>pos.x && mouse.y-62>(85*i)-62+225 && mouse.y-62<(85*i)+225)
        {
            sprite.setTexture(txt1);
        }else
            sprite.setTexture(txt2);
        window.draw(sprite);
        for(int j=0;j<6;j++)
            window.draw(text[j]);
    }
};

class crafting
{
private:
    sf::RenderWindow &window;
    sf::RectangleShape *shape;
    line *l[numberOfRecipes];
public:
    static bool showInterface;
    crafting(sf::RenderWindow &window1,sf::Vector2i DIM):window(window1)
    {
        shape=new sf::RectangleShape(sf::Vector2f((DIM.x-1000)*5.f,(DIM.y-300)*5.f));
        for(int i=0;i<numberOfRecipes;i++)
            l[i]=new line(window,1500,-1600+(i*400));
        shape->setFillColor(sf::Color(80,80,80,240));
        shape->setOutlineColor(sf::Color::Black);
        shape->setOutlineThickness(6);
    }
    void Update(sf::Vector2f pos);
};

#endif // CRAFTING_HPP_INCLUDED
