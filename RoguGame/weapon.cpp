#include "weapon.hpp"

weapon::weapon(sf::RenderWindow &window1):window(window1)
{
    txt.loadFromFile("Textures\\gun.png");
    sprite.setTexture(txt);
    sprite.setOrigin(350,500);
    sprite.setScale(0.3,0.3);
    fix=140;
}

void weapon::Update(sf::Vector2f Center)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.setRotation(315);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.setRotation(45);
        else
            sprite.setRotation(0);
    }else
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            sprite.setRotation(225);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.setRotation(135);
        else
            sprite.setRotation(180);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setRotation(90);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setRotation(270);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        fix=-140;
        if(-sprite.getScale().y<0)
            sprite.setScale(sprite.getScale().x,-sprite.getScale().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        fix=140;
        if(-sprite.getScale().y>0)
            sprite.setScale(sprite.getScale().x,-sprite.getScale().y);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        ammo.push_back(new ammunition(window,sprite.getPosition(),sprite.getRotation()));
    for(int i=0;i<ammo.size();i++)
        ammo[i]->Update(Center);
    sprite.setPosition(Center.x+fix,Center.y);
    window.draw(sprite);
}
