#include "Gate.hpp"

bool Gate::show=false;
sf::Vector2f Gate::startPos;

Gate::Gate(sf::RenderWindow &window1):window(window1)
{
    txt.loadFromFile("Textures\\gate.png");
    sprite.setTexture(txt);
    sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
    sprite.setScale(0.5,0.5);
    GochiHand_Regular.loadFromFile("Fonts\\GochiHand-Regular.ttf");
    text.setFont(GochiHand_Regular);
    text.setString("Wejdü [R]");
    text.setFillColor(sf::Color::Blue);
    text.setCharacterSize(110);
}
void Gate::Update(sf::Vector2f charPos)
{
    sprite.setPosition(startPos.x-charPos.x,startPos.y-charPos.y);
    text.setPosition(startPos.x-charPos.x,startPos.y-charPos.y-800);
    if(abs(charPos.x-sprite.getPosition().x)<600 && abs(charPos.y-sprite.getPosition().y)<600)
    {
        window.draw(text);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R) && clock.getElapsedTime().asSeconds()>0.5)
        {
            Level_Class::level++;
            clock.restart();
            show=false;
        }
    }
    window.draw(sprite);
}
void Gate::setPosition(sf::Vector2f newPos)
{
    startPos.x=newPos.x;
    startPos.y=newPos.y;
}
