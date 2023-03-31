#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

struct
{
    float Speed=0.001;
    float deltaTime(float TimeAsSec)
    {
        const float TimeX=600;
        float ret={1.f};
        ret=TimeAsSec*TimeX;
        return ret;
    }
    sf::Vector2i DIM;

}Config;

class background
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite[30][30];
public:
    background(sf::RenderWindow &window1,std::string path):window(window1)
    {
        txt.loadFromFile(path);
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
            {
                sprite[i][j].setTexture(txt);
                sprite[i][j].setPosition(i*1240,j*1240);
                sprite[i][j].setScale(10,10);
            }
    }
    void Update()
    {
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
                window.draw(sprite[i][j]);
    }
};
class character
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    sf::Clock clock;
    int i;
public:
    character(sf::RenderWindow &window1,std::string path):window(window1)
    {
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.6,0.6);
        sprite.setOrigin(400,700);
        i=0;
    };
    void Update(sf::Vector2f veCam)
    {
        sprite.setPosition(veCam);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                if(-sprite.getScale().x<0)
                    sprite.setScale(-sprite.getScale().x,sprite.getScale().y);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                if(-sprite.getScale().x>0)
                    sprite.setScale(-sprite.getScale().x,sprite.getScale().y);

            if(clock.getElapsedTime().asSeconds()>=0.2)
            {
                i++;
                if(i>2)
                    i=0;
                clock.restart();
            }
            sprite.setTextureRect(sf::IntRect(800*i,0,800,1400));
        }else
        {
            i=0;
            sprite.setTextureRect(sf::IntRect(2400,0,800,1400));
        }
        window.draw(sprite);
    }
};

int main()
{
    Config.DIM.x=1920;
    Config.DIM.y=1080;
    float BoostSpeed;
    sf::RenderWindow window(sf::VideoMode(Config.DIM.x,Config.DIM.y),"RogusGame");
    sf::View Camera;
    Camera.zoom(5.f);
    Camera.setCenter(18600,18600);
    background Background(window,"Textures//Grass.jpg");
    character Pawel(window,"Textures//pawe³.png");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            BoostSpeed=1.5f;
        else BoostSpeed=0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Camera.getCenter().x<34700)
            Camera.move(2.5f+BoostSpeed,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Camera.getCenter().x>2500)
            Camera.move(-2.5f-BoostSpeed,0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Camera.getCenter().x>2500)
            Camera.move(0,-1.5f-BoostSpeed);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Camera.getCenter().x<34700)
            Camera.move(0,1.5f+BoostSpeed);

        window.setView(Camera);
        window.clear(sf::Color(30,100,30));
        Background.Update();
        Pawel.Update(Camera.getCenter());
        window.display();
    }
    return 0;
}
