#include "weapon.hpp"

std::vector<ammunition*>weapon::ammo;

weapon::weapon(sf::RenderWindow &window1):window(window1)
{
    buffer.loadFromFile("Sounds\\piu_piu.wav");
    sound.setBuffer(buffer);
    txt.loadFromFile("Textures\\gun.png");
    sprite.setTexture(txt);
    sprite.setOrigin(350,500);
    sprite.setScale(0.3,0.3);
    fix=140;
}
void weapon::Destr(int i)
{
    delete ammo[i];
    ammo.erase(ammo.begin()+i);
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && Loading.getElapsedTime().asSeconds()>2.5f && equipment::Gun)
    {
        if(equipment::Bullets>0)
        {
            ammo.push_back(new ammunition(window,sprite.getPosition(),sprite.getRotation()));
            equipment::Bullets--;
            sound.play();
            Loading.restart();
        }

    }
    for(int i=0;i<ammo.size();i++)
        if(ammo[i]->Update(Center))
        {
            Destr(i);
        }
    sprite.setPosition(Center.x+fix,Center.y);
    window.draw(sprite);
}
