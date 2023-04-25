#include "Gate.hpp"

bool Gate::show=false;

Gate::Gate(sf::RenderWindow &window1):window(window1)
{
    txt.loadFromFile("Textures\\gate.png");
    sprite.setTexture(txt);
}
void Gate::Update(sf::Vector2f charPos)
{
    sprite.setPosition(charPos.x,charPos.y);
    window.draw(sprite);
}
void Gate::setPosition(sf::Vector2f newPos)
{
    pos=newPos;
}
