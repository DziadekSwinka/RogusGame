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
bool ammunition::Update(sf::Vector2f Camera,double FTime)
{
    a=speed*(sin(DIR));
    b=speed*(cos(DIR));
    pos.x+=b*FTime;
    pos.y+=a*FTime;
    sprite.setPosition(Camera.x+pos.x,Camera.y+pos.y);
    if(Camera.x+pos.x<=0 || Camera.y+pos.y<=0 || Camera.x+pos.x>=37200 || Camera.y+pos.y>=37200)
    {
         return true;
    }
    window.draw(sprite);
    return false;
}
