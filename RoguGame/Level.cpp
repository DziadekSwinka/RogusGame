#ifndef LEVEL_CPP_INCLUDED
#define LEVEL_CPP_INCLUDED

#include "Level.hpp"

int Level_Class::level=1;
int Level_Class::toNextLevel[NumberLevels]={1,1};

bool Level_Class::operator++()
{
    if(level<NumberLevels)
    {
        level+=1;
        return true;
    }else return false;
}

void Level_Class::Update(sf::Vector2f Camera,SoundEvent *Sound,Gate &gate,double FTime)
{
    levelConfig &thisLevel=levels[level];
    if(thisLevel.usingCharakters[0])
        for(int i=0;i<static_cast<int>(chochol.size());i++)
            chochol[i]->Update(Camera,Sound,hand_weapon::hurt_by_hand,gate,FTime);
    if(thisLevel.usingCharakters[1])
        for(int i=0;i<static_cast<int>(mushroom.size());i++)
            mushroom[i]->Update(Camera,Sound,hand_weapon::hurt_by_hand,gate,FTime);
    if(thisLevel.usingCharakters[2])
        for(int i=0;i<static_cast<int>(chocholP.size());i++)
            chocholP[i]->Update(Camera,Sound,hand_weapon::hurt_by_hand,gate,FTime);
    if(thisLevel.usingCharakters[3])
        for(int i=0;i<static_cast<int>(chocholA.size());i++)
            chocholA[i]->Update(Camera,Sound,hand_weapon::hurt_by_hand,gate,FTime);
    if(thisLevel.usingCharakters[4])
        for(int i=0;i<static_cast<int>(chocholS.size());i++)
            chocholS[i]->Update(Camera,Sound,hand_weapon::hurt_by_hand,gate,FTime);
}

Level_Class::Level_Class(std::vector<enemy*>&t1,std::vector<enemy*>&t2,std::vector<heavy_enemy*>&t3,std::vector<axe_enemy*>&t4,std::vector<shovel_enemy*>&t5,sf::RenderWindow &window)
    :chochol(t1),mushroom(t2),chocholP(t3),chocholA(t4),chocholS(t5)
{
    levelConfig &l1=levels[1];
    levelConfig &l2=levels[2];

    l1.usingCharakters[0]=1;
    l1.usingCharakters[1]=0;
    l1.usingCharakters[2]=1;
    l1.usingCharakters[3]=1;
    l1.usingCharakters[4]=1;

    l2.usingCharakters[0]=0;
    l2.usingCharakters[1]=1;
    l2.usingCharakters[2]=0;
    l2.usingCharakters[3]=1;
    l2.usingCharakters[4]=0;

    for(int i=0;i<20;i++)
        chochol.push_back(new enemy(window,"Textures\\chochol.png","Textures\\chochol_dmg.png"));
    for(int i=0;i<20;i++)
        mushroom.push_back(new mush_enemy(window,"Textures\\Grzyb.png","Textures\\Grzyb.png"));
    for(int i=0;i<12;i++)
        chocholP.push_back(new heavy_enemy(window,"Textures\\chochol_pancerny.png","Textures\\chochol_pancerny_dmg.png"));
    for(int i=0;i<6;i++)
        chocholA.push_back(new axe_enemy(window,"Textures\\chochol_siekiera.png","Textures\\chochol_siekiera_dmg.png"));
    for(int i=0;i<6;i++)
        chocholS.push_back(new shovel_enemy(window,"Textures\\chochol_lopata.png","Textures\\chochol_lopata_dmg.png"));
}

#endif // LEVEL_CPP_INCLUDED
