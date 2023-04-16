#include "Application.hpp"

void prep_txt_items()
{
     stat.txt[0].loadFromFile("Textures\\stone.png");
     stat.txt[1].loadFromFile("Textures\\stick.png");
     stat.txt[2].loadFromFile("Textures\\flower1.png");
     stat.txt[3].loadFromFile("Textures\\flower2.png");
}

void Application()
{
    Config.DIM.x=1920;
    Config.DIM.y=1080;
    float BoostSpeed;
    sf::Sprite Title;
    sf::Texture TitleTxt;
    TitleTxt.loadFromFile("Textures//Title.jpg");
    Title.setTexture(TitleTxt);
    sf::RenderWindow window(sf::VideoMode(Config.DIM.x,Config.DIM.y),"RogusGame");
    window.draw(Title);
    window.display();

    std::vector<enemy*>(chochol);
    for(int i=0;i<10;i++)
        chochol.push_back(new enemy(window,"Textures\\chochol.png"));
    crafting Crafting(window,/*static_cast<sf::Vector2f>*/(Config.DIM));
    prep_txt_items();
    vec.ini(&window);

    sf::Clock TabTime;
    sf::View Camera;
    Camera.zoom(Config.zoom);
    Camera.setCenter(18600,18600);
    background Background(window,"Textures//Grass.jpg");

    character Pawel(window,"Textures//pawel.png");

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
            if(event.type==sf::Event::MouseWheelMoved)
            {
                Config.zoom+=event.mouseWheel.delta;
                Camera.zoom(Config.zoom);
            }
        }
        if(!Crafting.showInterface)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                BoostSpeed=1.5f;
            else BoostSpeed=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Camera.getCenter().x<34700)
                Camera.move(2.5f+BoostSpeed,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Camera.getCenter().x>2500)
                Camera.move(-2.5f-BoostSpeed,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Camera.getCenter().y>2500)
                Camera.move(0,-1.5f-BoostSpeed);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Camera.getCenter().y<34700)
                Camera.move(0,1.5f+BoostSpeed);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && TabTime.getElapsedTime().asSeconds()>=0.2f)
        {
            if(Crafting.showInterface==true)
                Crafting.showInterface=false;
            else Crafting.showInterface=true;
            TabTime.restart();
        }


        window.setView(Camera);
        window.clear(sf::Color(30,100,30));
        Background.Update();
        vec.VectorsUpdate(Pawel,&window);
        for(int i=0;i<chochol.size();i++)
            chochol[i]->Update(Camera.getCenter());
        Pawel.Update(Camera.getCenter());
        if(Crafting.showInterface)
            Crafting.Update(Camera.getCenter());
        window.display();
    }
}
