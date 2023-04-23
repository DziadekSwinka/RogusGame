#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

#include "Level.hpp"

class background
{
private:
    sf::RenderWindow &window;
    sf::Texture txt[Level_Class::NumberLevels];
    sf::Sprite sprite[30][30];
    int actualLevel;
public:
    background(sf::RenderWindow &window1,std::string path1,std::string path2):window(window1)
    {
        txt[0].loadFromFile(path1);
        txt[1].loadFromFile(path2);
        actualLevel=Level_Class::level;
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
            {
                sprite[i][j].setTexture(txt[actualLevel-1]);
                sprite[i][j].setPosition(i*1240,j*1240);
                sprite[i][j].setScale(10,10);
            }
    }
    void Update()
    {
        if(actualLevel!=Level_Class::level)
        {
            actualLevel=Level_Class::level;
            for(int i=0;i<30;i++)
                for(int j=0;j<30;j++)
                    sprite[i][j].setTexture(txt[actualLevel-1]);
        }
        for(int i=0;i<30;i++)
            for(int j=0;j<30;j++)
                window.draw(sprite[i][j]);
    }
};

#endif // BACKGROUND_HPP_INCLUDED
