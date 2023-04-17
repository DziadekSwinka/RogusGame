#include "ammunition.hpp"

ammunition::ammunition(sf::RenderWindow &window1,sf::Vector2f pos,float dir):window(window1)
{
    speed=4;
    txt.loadFromFile("Textures\\bullet.png");
    sprite.setTexture(txt);
    sprite.setScale(0.35,0.35);
    sprite.setRotation(dir+90);
    DIR=dir*(M_PI/180.f);
}
void ammunition::Update(sf::Vector2f Camera)
{
    a=speed*(sin(DIR));
    b=speed*(cos(DIR));
    pos.x+=b;
    pos.y+=a;
    sprite.setPosition(Camera.x+pos.x,Camera.y+pos.y);
    window.draw(sprite);
}
