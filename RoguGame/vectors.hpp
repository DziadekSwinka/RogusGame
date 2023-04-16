#ifndef VECTORS_HPP_INCLUDED
#define VECTORS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "items.hpp"
#include "equipment.hpp"


struct
{
    std::vector<item*>(stone);
    std::vector<item*>(stick);
    std::vector<item*>(f1);
    std::vector<item*>(f2);
    std::vector<item*>(ore);



    void VectorsUpdate(character &P,sf::RenderWindow *window)
    {
        equipment tmpEQ(*window);

        for(int i=0;i<stone.size();i++)
            if(stone[i]->Update(P)){
                tmpEQ.Stone++;
                delete stone[i];
                stone.erase(stone.begin()+i);
                stone.push_back(new item(*window,0));
            }

        for(int i=0;i<stick.size();i++)
            if(stick[i]->Update(P)){
                tmpEQ.Stick++;
                delete stick[i];
                stick.erase(stick.begin()+i);
                stick.push_back(new item(*window,1));
            }

        for(int i=0;i<f1.size();i++)
            if(f1[i]->Update(P)){
                tmpEQ.Flower1++;
                delete f1[i];
                f1.erase(f1.begin()+i);
                f1.push_back(new item(*window,2));
            }

        for(int i=0;i<f2.size();i++)
            if(f2[i]->Update(P)){
                tmpEQ.Flower2++;
                delete f2[i];
                f2.erase(f2.begin()+i);
                f2.push_back(new item(*window,3));
            }
        for(int i=0;i<ore.size();i++)
            if(ore[i]->Update(P)){
                tmpEQ.Ore++;
                delete ore[i];
                ore.erase(ore.begin()+i);
                ore.push_back(new item(*window,4));
            }
    }
    void ini(sf::RenderWindow *window)
    {
        for(int i=0;i<60;i++)
            stone.push_back(new item(*window,0));
        for(int i=0;i<45;i++)
            stick.push_back(new item(*window,1));
        for(int i=0;i<30;i++)
        {
            f1.push_back(new item(*window,2));
            f2.push_back(new item(*window,3));
        }
        for(int i=0;i<15;i++)
            ore.push_back(new item(*window,4));
    }
}vec;

#endif // VECTORS_HPP_INCLUDED
