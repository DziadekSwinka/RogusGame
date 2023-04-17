#ifndef CRAFTING_HPP_INCLUDED
#define CRAFTING_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "recipe.hpp"


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
    void Update(sf::Vector2f Center, int i)
    {
        sprite.setPosition(Center.x+pos.x-750,Center.y+pos.y);
        for(int j=0;j<5;j++)    //without no.5 element
        {
            text[j].setPosition(Center.x+pos.x-900-200*j,Center.y+pos.y+50);
            text[j].setString(std::to_string(recipe.ingr[i][j]));
        }
        text[5].setString(recipe.name[i]);
        text[5].setPosition(Center.x+pos.x-900-1800,Center.y+pos.y+50);

        sf::Vector2i mouse=sf::Mouse::getPosition();
        sf::Vector2f button=sprite.getPosition();
        if(mouse.x-125<pos.x && mouse.x+125>pos.x && mouse.y-62>(85*i)-62+225 && mouse.y-62<(85*i)+225)
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
    sf::Texture icon[5];
    sf::Sprite Sicon[5];
public:
    static bool showInterface;
    crafting(sf::RenderWindow &window1,sf::Vector2i DIM):window(window1)
    {
        shape=new sf::RectangleShape(sf::Vector2f((DIM.x-1000)*5.f,(DIM.y-300)*5.f));
        for(int i=0;i<numberOfRecipes;i++)
            l[i]=new line(window,1250,-1600+(i*400));
        for(int i=0;i<5;i++)
            if(i!=1)
                Sicon[i].setScale(0.1,0.1);
            else Sicon[1].setScale(0.03,0.1);
        icon[0].loadFromFile("Textures\\stone.png");
        icon[1].loadFromFile("Textures\\stick.png");
        icon[2].loadFromFile("Textures\\ore.png");
        icon[3].loadFromFile("Textures\\flower1.png");
        icon[4].loadFromFile("Textures\\flower2.png");

        for(int i=0;i<5;i++)
                Sicon[i].setTexture(icon[i]);
        shape->setFillColor(sf::Color(80,80,80,240));
        shape->setOutlineColor(sf::Color::Black);
        shape->setOutlineThickness(6);
    }
    void Update(sf::Vector2f pos);
};

#endif // CRAFTING_HPP_INCLUDED
