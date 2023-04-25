#include "chest.hpp"

sf::Texture chest::txt;
bool chest::isLoaded=false;

void chest::Update(character &P)
{
    window.draw(sprite);
}
