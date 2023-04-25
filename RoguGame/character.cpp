#include "character.hpp"

bool character::ScaleX=true;

void character::Update(sf::Vector2f veCam,double FTime)
    {
        Center=veCam;
        HP=equip->HP;
        sprite.setPosition(Center);
        pickUp.setPosition(Center.x-250,Center.y-800);
        red_rect->setPosition(Center.x-250,Center.y-600);
        white_rect->setPosition(Center.x-250,Center.y-600);
        if(crafting::showInterface==false)
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                if(sound.getStatus()!=sf::Sound::Playing)
                    sound.play();
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    if(-sprite.getScale().x<0)
                    {
                        sprite.setScale(-sprite.getScale().x,sprite.getScale().y);
                        ScaleX=0;
                    }

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    if(-sprite.getScale().x>0)
                    {
                        sprite.setScale(-sprite.getScale().x,sprite.getScale().y);
                        ScaleX=1;
                    }

                if(clock.getElapsedTime().asSeconds()>=0.2)
                {
                    i++;
                    if(i>2)
                        i=0;
                    clock.restart();
                }
                if(!crafting::showInterface && HP>0)
                    sprite.setTextureRect(sf::IntRect(800*i,0,800,1400));
            }else
            {
                sound.stop();
                i=0;
                sprite.setTextureRect(sf::IntRect(2400,0,800,1400));
                if(HP<=0)
                {
                    sprite.setTextureRect(sf::IntRect(800*4,0,800,1400));
                }
            }
        Rsize=sf::Vector2f(HP*5,red_rect->getSize().y);
        red_rect->setSize(Rsize);
        window.draw(sprite);
        if(equipment::Gun && equipment::hand==2)
            gun->Update(veCam,FTime);
        if(equipment::Axe && equipment::hand==3)
        {
            axe->Update(veCam,ScaleX);
        }
        if(equipment::Shovel && equipment::hand==4)
        {
            shovel->Update(veCam,ScaleX);
        }
        if(equipment::Sword && equipment::hand==5)
        {
            sword->Update(veCam,ScaleX);
        }
        if(HP>0)
        {
            window.draw(*white_rect);
            window.draw(*red_rect);
            if(showText)
                window.draw(pickUp);
        }
        showText=false;
        if(!crafting::showInterface)
            equip->Update(sprite.getPosition());
    }
