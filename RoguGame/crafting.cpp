#include "crafting.hpp"

bool crafting::showInterface=false;

void crafting::Update(sf::Vector2f pos)
{
    shape->setPosition(pos.x-2300,pos.y-1900);
    window.draw(*shape);
    for(int i=0;i<numberOfRecipes;i++)
        l[i]->Update(pos,i);
    for(int i=0;i<5;i++)
    {
        Sicon[4-i].setPosition(pos.x-500+i*210,pos.y-1800);
        window.draw(Sicon[i]);
    }

}
void line::craft(int n)
{
    const int NumberOfItems=5;
    unsigned int *k[NumberOfItems];
    int counter=0;
    if(n==3 && equipment::Gun==true)
    {
        return;
    }
    for(int i=0;i<NumberOfItems;i++)
    {
        switch(i)
        {
        case 0:
            k[i]=&equipment::Stone;
            break;
        case 1:
            k[i]=&equipment::Stick;
            break;
        case 2:
            k[i]=&equipment::Ore;
            break;
        case 3:
            k[i]=&equipment::Flower1;
            break;
        case 4:
            k[i]=&equipment::Flower2;
            break;
        default: i=NumberOfItems+1; break;
        }
        if(*k[i]>=recipe.ingr[n][i])
            counter++;
    }
    if(counter==NumberOfItems)
    {
        for(int i=0;i<NumberOfItems;i++)
            *k[i]=*k[i]-recipe.ingr[n][i];
        switch(n)
        {
        case 3:
            equipment::Gun=true;
            break;
        case 4:
            equipment::Bullets+=10;
            break;
        default: break;
        }
    }
    else return;
}
