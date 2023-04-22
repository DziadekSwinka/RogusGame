#include "Application.hpp"

void prep_txt_items()
{
     stat.txt[0].loadFromFile("Textures\\stone.png");
     stat.txt[1].loadFromFile("Textures\\stick.png");
     stat.txt[2].loadFromFile("Textures\\flower1.png");
     stat.txt[3].loadFromFile("Textures\\flower2.png");
     stat.txt[4].loadFromFile("Textures\\ore.png");
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
    progressBar PBar(window,Title);
//----------------------------------------Wczytano okno tytulowe------------------------------------------------
    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile("Sounds\\Otjanbird-Pt.-II.wav");
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.setVolume(20);
    PBar.Progress(15);
    std::vector<enemy*>(chochol);
    PBar.Progress(25);
    std::vector<mush_enemy*>(mushroom);
    PBar.Progress(35);
    std::vector<heavy_enemy*>(chocholP);
    PBar.Progress(45);
    std::vector<axe_enemy*>(chocholA);
    PBar.Progress(55);
    std::vector<shovel_enemy*>(chocholS);
    PBar.Progress(65);
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
    PBar.Progress(85);
    crafting Crafting(window,Config.DIM);
    PBar.Progress(90);
    prep_txt_items();
    vec.ini(&window);

    sf::Clock TabTime;
    sf::View Camera;
    Camera.zoom(Config.zoom);
    Camera.setCenter(18600,18600);
    background Background(window,"Textures//sand.jpg");
    SoundEvent *Sound=new SoundEvent();
    character Pawel(window,"Textures//pawel.png");
    PBar.Progress(100);
    sound.play();
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        if(!Crafting.showInterface && Pawel.HP>0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                BoostSpeed=0.3f;
            else BoostSpeed=0;
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Camera.getCenter().x<34700)
                Camera.move(1.2f+BoostSpeed,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Camera.getCenter().x>2500)
                Camera.move(-1.2f-BoostSpeed,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Camera.getCenter().y>2500)
                Camera.move(0,-1.2f-BoostSpeed);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Camera.getCenter().y<34700)
                Camera.move(0,1.2f+BoostSpeed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab) && TabTime.getElapsedTime().asSeconds()>=0.2f)
        {
            if(Crafting.showInterface==true)
                Crafting.showInterface=false;
            else Crafting.showInterface=true;
            TabTime.restart();
        }
        Sound->update();
        window.setView(Camera);
        window.clear(sf::Color(30,100,30));
        Background.Update();
        vec.VectorsUpdate(Pawel,&window);
        for(int i=0;i<chochol.size();i++)
            chochol[i]->Update(Camera.getCenter(),Sound);
        for(int i=0;i<mushroom.size();i++)
            mushroom[i]->Update(Camera.getCenter(),Sound);
        for(int i=0;i<chocholP.size();i++)
            chocholP[i]->Update(Camera.getCenter(),Sound);
        for(int i=0;i<chocholA.size();i++)
            chocholA[i]->Update(Camera.getCenter(),Sound);
        for(int i=0;i<chocholS.size();i++)
            chocholS[i]->Update(Camera.getCenter(),Sound);
        Pawel.Update(Camera.getCenter());
        if(Crafting.showInterface)
            Crafting.Update(Camera.getCenter());
        window.display();
    }
}
