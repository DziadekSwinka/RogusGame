#ifndef RECIPE_HPP_INCLUDED
#define RECIPE_HPP_INCLUDED

const int numberOfRecipes=6;

struct
{
        std::string name[numberOfRecipes]={"Lopata","Kilof","Drewniany miecz","Pistolet","Amunicja","Piwo"};
        unsigned int ingr[numberOfRecipes][5]= {{4,3,0,0,0},     //sticks/stone/ore/flower1/flower2
                                                {5,5,0,0,0},
                                                {5,1,0,0,0},
                                                {0,5,10,0,0},
                                                {0,2,5,0,0},
                                                {1,0,0,5,5}};
}recipe;

#endif // RECIPE_HPP_INCLUDED