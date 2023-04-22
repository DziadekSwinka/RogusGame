#include "Enemy.hpp"

std::vector<ThrowedItem*>mush_enemy::throwed={0};

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
void enemy::Update(sf::Vector2f characterPos,SoundEvent *Sound)
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
        if(abs(characterPos.x-pos.x)<500 && abs(characterPos.y-pos.y)<500 && time.getElapsedTime().asSeconds()>AttackTime)
        {
            if(equipment::HP<DMG_rate && equipment::HP>0)
                equipment::HP=0;
            if(equipment::HP>=DMG_rate)
                equipment::HP-=DMG_rate;
            time.restart();
        }
        if(abs(characterPos.x-pos.x)<6000 && abs(characterPos.y-pos.y)<6000 && !crafting::showInterface)
            collision(characterPos,Sound);
        if(dmgTime.getElapsedTime().asSeconds()>0.3)
            noTxt=1;
        if(noTxt)
            sprite.setTexture(txt);
        else
            sprite.setTexture(txt_dmg);
        sprite.setPosition(pos.x,pos.y);
        window.draw(sprite);
    }

}void mush_enemy::Update(sf::Vector2f characterPos,SoundEvent *Sound)
{
    if(HP>0)
    {
        if(abs(characterPos.x-pos.x)<2500 && abs(characterPos.y-pos.y)<2500 && !crafting::showInterface)
        {
            /*if(updateTime.getElapsedTime().asSeconds()>0.1f)
            {
                */alpha=calcDir(characterPos);
                /*updateTime.restart();
            }
            /*alpha+=(std::rand()%2)-1;*/
            a=c*(sin(alpha));
            b=c*(cos(alpha));
            pos.x+=b;
            pos.y+=a;
        }
        if(abs(characterPos.x-pos.x)<2000 && abs(characterPos.y-pos.y)<2000 && time.getElapsedTime().asSeconds()>AttackTime)
        {
            throwed.push_back(new ThrowedItem(window,pos,alpha/(M_PI/180.f)));
            time.restart();
        }
        if(abs(characterPos.x-pos.x)<2000 && abs(characterPos.y-pos.y)<2000 && !crafting::showInterface)
            collision(characterPos,Sound);
        if(dmgTime.getElapsedTime().asSeconds()>0.3)
            noTxt=1;
        if(noTxt)
            sprite.setTexture(txt);
        else
            sprite.setTexture(txt_dmg);
        sprite.setPosition(pos.x,pos.y);
        window.draw(sprite);
        for(int i=throwed.size()-1;i>0;i--)
            if(throwed[i]->Update(characterPos)==true)
            {
                delete throwed[i];
                throwed.erase(throwed.begin()+i);
            }

    }
}
double enemy::calcDir(sf::Vector2f characterPos)
{
    double dir;
    dir=tan((characterPos.y-pos.y)/(characterPos.x-pos.x));
    dir/=M_PI/180.f;      //to degree
    return dir;
}
void enemy::collision(sf::Vector2f charPos,SoundEvent *Sound)
{
    for(int i=0;i<weapon::ammo.size();i++)
    {
        sf::Vector2f AMpos=weapon::ammo[i]->pos;
        if(AMpos.x+charPos.x>pos.x-txt.getSize().x && AMpos.x+charPos.x<pos.x+txt.getSize().x)
            if(AMpos.y+charPos.y>pos.y-txt.getSize().y && AMpos.y+charPos.y<pos.y+txt.getSize().y)
            {
                weapon::Destr(i);
                injur(Sound);
            }
    }
}
void enemy::injur(SoundEvent *Sound)
{
    if(HP>=50)
        HP-=50;
    if(HP==0)
    {
       Sound->pushToQueue(std::rand()%6);
    }
    noTxt=0;
    dmgTime.restart();
}
