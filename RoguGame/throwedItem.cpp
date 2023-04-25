#include "throwedItem.hpp"

ThrowedItem::ThrowedItem(sf::RenderWindow &window1,sf::Vector2f startPos,double alpha):window(window1)
{
    txt.loadFromFile("Textures\\"+path[(std::rand()%5)-0]);
    sprite.setTexture(txt);
    sprite.setPosition(startPos);
    sprite.setScale(1,1);
    sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
    rotationRate=0.005;
    c=0.13f;
    a=c*(sin(alpha));
    b=c*(cos(alpha));
}
bool ThrowedItem::Update(sf::Vector2f charpos,double FTime)
{
    if(charpos.x+pos.x<=0 || charpos.y+pos.y<=0 || charpos.x+pos.x>=37200 || charpos.y+pos.y>=37200)
        return true;
    sprite.rotate(rotationRate*FTime);
    sprite.move(b*FTime,a*FTime);
    window.draw(sprite);
    return false;
}
