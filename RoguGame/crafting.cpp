#include "crafting.hpp"

bool crafting::showInterface=false;

void crafting::Update(sf::Vector2f pos)
{
    shape->setPosition(pos.x-2300,pos.y-1900);
    window.draw(*shape);
    l1->Update(pos);
}
