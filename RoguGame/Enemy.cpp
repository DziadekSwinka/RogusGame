#include "Enemy.hpp"

void enemy::Update(sf::Vector2f characterPos)
{
    if(isAlive)
    {
        if(abs(characterPos.x-pos.x)<2500 && abs(characterPos.y-pos.y)<2500 && !crafting::showInterface)
        {
            alpha=calcDir(characterPos);
            /*alpha+=(std::rand()%2)-1;*/
            a=c*(sin(alpha));
            b=c*(cos(alpha));
            pos.x+=b;
            pos.y+=a;
        }
        if(abs(characterPos.x-pos.x)<500 && abs(characterPos.y-pos.y)<500 && time.getElapsedTime().asSeconds()>3)
        {
            if(equipment::HP<5 && equipment::HP>0)
                equipment::HP=0;
            if(equipment::HP>=5)
                equipment::HP-=5;
            time.restart();
        }
        //if(abs(characterPos.x-pos.x)<6000 && abs(characterPos.y-pos.y)<6000 && !crafting::showInterface)
            collision();
        sprite.setPosition(pos.x,pos.y);
        window.draw(sprite);
    }
}
double enemy::calcDir(sf::Vector2f characterPos)
{
    double dir;
    dir=tan((characterPos.y-pos.y)/(characterPos.x-pos.x));
    //dir/=M_PI/180.f;      //to degree
    return dir;
}
void enemy::collision()
{
    for(int i=0;i<weapon::ammo.size();i++)
    {
        sf::Vector2f AMpos=weapon::ammo[i]->pos;
        if(AMpos.x>pos.x+txt.getSize().x && AMpos.x<pos.x-txt.getSize().x)
            if(AMpos.y>pos.y+txt.getSize().y && AMpos.y<pos.y-txt.getSize().y)
                weapon::Destr(i);
    }
}
