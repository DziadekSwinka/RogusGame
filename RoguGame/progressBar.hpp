#ifndef PROGRESSBAR_HPP_INCLUDED
#define PROGRESSBAR_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class progressBar
{
private:
    sf::RenderWindow &window;
    sf::RectangleShape *Front,*Back;
    sf::CircleShape *Left,*Right;
    sf::Sprite &sprite;
public:
    progressBar(sf::RenderWindow &window1,sf::Sprite &s):window(window1),sprite(s)
    {
        Front=new sf::RectangleShape(sf::Vector2f(0,50));
        Back=new sf::RectangleShape(sf::Vector2f(800,50));
        Left=new sf::CircleShape(25);
        Right=new sf::CircleShape(25);
        Front->setPosition(560,800);
        Back->setPosition(560,800);
        Left->setPosition(535,800);
        Right->setPosition(1335,800);
        Front->setFillColor(sf::Color::Red);
        window.draw(sprite);
        window.draw(*Back);
        window.draw(*Front);
        window.draw(*Left);
        window.draw(*Right);
        window.display();
    }
    void Progress(int percent)
    {
        if(percent>=5)
            Left->setFillColor(sf::Color::Red);
        else
            Left->setFillColor(sf::Color::White);
        if(percent>=95)
            Right->setFillColor(sf::Color::Red);
        else
            Right->setFillColor(sf::Color::White);
        Front->setSize(sf::Vector2f(8*percent,50));
        window.clear();
        window.draw(sprite);
        window.draw(*Back);
        window.draw(*Front);
        window.draw(*Left);
        window.draw(*Right);
        window.display();
    }
};

#endif // PROGRESSBAR_HPP_INCLUDED
