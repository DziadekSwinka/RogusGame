#ifndef VECTORS_HPP_INCLUDED
#define VECTORS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>

#include "items.hpp"
#include "equipment.hpp"
#include "chest.hpp"

struct
{
    std::vector<item*>stone;
    std::vector<item*>stick;
    std::vector<item*>f1;
    std::vector<item*>f2;
    std::vector<item*>ore;
    std::vector<item*>plastic;

    std::vector<chest*>Chest;

    void VectorsUpdate(character &P,sf::RenderWindow *window)
    {
        equipment tmpEQ(*window);

        for(int i=0;i<static_cast<int>(stone.size());i++)
            if(stone[i]->Update(P)){
                tmpEQ.Stone++;
                delete stone[i];
                stone.erase(stone.begin()+i);
                stone.push_back(new item(*window,0));
            }

        for(int i=0;i<static_cast<int>(stick.size());i++)
            if(stick[i]->Update(P)){
                tmpEQ.Stick++;
                delete stick[i];
                stick.erase(stick.begin()+i);
                stick.push_back(new item(*window,1));
            }

        for(int i=0;i<static_cast<int>(f1.size());i++)
            if(f1[i]->Update(P)){
                tmpEQ.Flower1++;
                delete f1[i];
                f1.erase(f1.begin()+i);
                f1.push_back(new item(*window,2));
            }

        for(int i=0;i<static_cast<int>(f2.size());i++)
            if(f2[i]->Update(P)){
                tmpEQ.Flower2++;
                delete f2[i];
                f2.erase(f2.begin()+i);
                f2.push_back(new item(*window,3));
            }
        for(int i=0;i<static_cast<int>(ore.size());i++)
            if(ore[i]->Update(P)){
                tmpEQ.Ore++;
                delete ore[i];
                ore.erase(ore.begin()+i);
                ore.push_back(new item(*window,4));
            }
        for(int i=0;i<static_cast<int>(plastic.size());i++)
            if(plastic[i]->Update(P)){
                tmpEQ.Plastic++;
                delete plastic[i];
                plastic.erase(plastic.begin()+i);
                plastic.push_back(new item(*window,5));
            }
        /*for(int i=0;i<Chest.size();i++)
            Chest[i]->Update(P);
        std::cout<<Chest.size()<<std::endl;*/
    }
    void ini(sf::RenderWindow *window)
    {
        for(int i=0;i<50;i++)
            stone.push_back(new item(*window,0));
        for(int i=0;i<35;i++)
            stick.push_back(new item(*window,1));
        for(int i=0;i<20;i++)
        {
            f1.push_back(new item(*window,2));
            f2.push_back(new item(*window,3));
        }
        for(int i=0;i<15;i++)
            ore.push_back(new item(*window,4));
        for(int i=0;i<15;i++)
            plastic.push_back(new item(*window,5));
    }
}vec;

#endif // VECTORS_HPP_INCLUDED
