#include "chest.hpp"

sf::Texture chest::txt;
bool chest::isLoaded=false;

void chest::Update(character &P)
{
    cout<<sprite.getPosition().x<<"\t"<<sprite.getPosition().y<<endl;
    window.draw(sprite);
}
