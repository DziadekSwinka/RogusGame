#include "equipment.hpp"

void equipment::Update(sf::Vector2f pos)
{
    backRect.setPosition(pos.x,pos.y+1700);
    window.draw(backRect);
}
