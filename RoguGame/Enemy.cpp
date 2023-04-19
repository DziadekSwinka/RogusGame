#include "Enemy.hpp"

void enemy::ini(std::string path,std::string path2)
{
    noTxt=1;
    txt.loadFromFile(path);
    txt_dmg.loadFromFile(path2);
    sprite.setTexture(txt);
    sprite.setTexture(txt);
    sprite.setScale(2.f,2.f);
    sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
    pos.x=(rand()%34700)+2500;
    pos.y=(rand()%34700)+2500;
}
void enemy::Update(sf::Vector2f characterPos)
{
    if(HP>0)
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
            if(equipment::HP<DMG_rate && equipment::HP>0)
                equipment::HP=0;
            if(equipment::HP>=DMG_rate)
                equipment::HP-=DMG_rate;
            time.restart();
        }
        if(abs(characterPos.x-pos.x)<6000 && abs(characterPos.y-pos.y)<6000 && !crafting::showInterface)
            collision(characterPos);
        if(dmgTime.getElapsedTime().asSeconds()>0.3)
            noTxt=1;
        if(noTxt)
            sprite.setTexture(txt);
        else
            sprite.setTexture(txt_dmg);
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
void enemy::collision(sf::Vector2f charPos)
{
    for(int i=0;i<weapon::ammo.size();i++)
    {
        sf::Vector2f AMpos=weapon::ammo[i]->pos;
        if(AMpos.x+charPos.x>pos.x-txt.getSize().x && AMpos.x+charPos.x<pos.x+txt.getSize().x)
            if(AMpos.y+charPos.y>pos.y-txt.getSize().y && AMpos.y+charPos.y<pos.y+txt.getSize().y)
            {
                weapon::Destr(i);
                injur();
            }
    }
}
void enemy::injur()
{
    if(HP>=50)
        HP-=50;
    /*if(HP==0)
    {
        vec.f1.push_back(new item(window,pos,2));       //nie dziala
    }*/

    noTxt=0;
    dmgTime.restart();
}
