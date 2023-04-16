#ifndef CRAFTING_HPP_INCLUDED
#define CRAFTING_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

class line
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt1,txt2;
    sf::Vector2f pos;
public:
    line(sf::RenderWindow &window1,float posX,float posY):window(window1)
    {
        pos=sf::Vector2f(posX,posY);
        txt1.loadFromFile("Textures\\GUI\\wytworz1.png");
        txt2.loadFromFile("Textures\\GUI\\wytworz2.png");
    }
    void Update(sf::Vector2f DIM)
    {
        sprite.setPosition(DIM.x+pos.x,DIM.y+pos.y);
        sf::Vector2i mouse=sf::Mouse::getPosition(window);
        //sf::Vector2i mouse1=sf::Mouse::getPosition();
        std::cout<<mouse.x<<" "<<-1920+mouse.y<<"\t"<<pos.x<<" "<<pos.y<<std::endl;
        sf::Vector2f button=sprite.getPosition();
        if(mouse.x<pos.x+500 && mouse.x>pos.x && -1920+mouse.y>pos.y+250 && -1920+mouse.y<pos.y)
        {
            sprite.setTexture(txt1);
        }else
            sprite.setTexture(txt2);
        window.draw(sprite);
    }
};

class crafting
{
private:
    sf::RenderWindow &window;
    sf::RectangleShape *shape;
    line *l1;
public:
    static bool showInterface;
    crafting(sf::RenderWindow &window1,sf::Vector2i DIM):window(window1)
    {
        shape=new sf::RectangleShape(sf::Vector2f((DIM.x-1000)*5.f,(DIM.y-300)*5.f));
        l1=new line(window,1500,-1600);
        shape->setFillColor(sf::Color(80,80,80,240));
        shape->setOutlineColor(sf::Color::Black);
        shape->setOutlineThickness(6);
    }
    void Update(sf::Vector2f pos);
};

#endif // CRAFTING_HPP_INCLUDED
