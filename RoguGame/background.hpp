#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

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

#endif // BACKGROUND_HPP_INCLUDED
