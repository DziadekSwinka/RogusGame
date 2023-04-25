#include "Application.hpp"

void prep_txt_items()
{
     stat.txt[0].loadFromFile("Textures\\stone.png");
     stat.txt[1].loadFromFile("Textures\\stick.png");
     stat.txt[2].loadFromFile("Textures\\flower1.png");
     stat.txt[3].loadFromFile("Textures\\flower2.png");
     stat.txt[4].loadFromFile("Textures\\ore.png");
     stat.txt[5].loadFromFile("Textures\\plastic1.png");
     stat.txt[6].loadFromFile("Textures\\plastic2.png");
     stat.txt[7].loadFromFile("Textures\\plastic3.png");
     stat.txt[8].loadFromFile("Textures\\plastic4.png");
}

void Application()
{
    Config.DIM.x=1920;
    Config.DIM.y=1080;
    float BoostSpeed;
    sf::Sprite Title;
    sf::Texture TitleTxt;
    sf::RenderWindow window(sf::VideoMode(Config.DIM.x,Config.DIM.y),"RogusGame");
    //window.setFramerateLimit(60);
    TitleTxt.loadFromFile("Textures//Title.jpg");
    Title.setTexture(TitleTxt);
    window.draw(Title);
    progressBar PBar(window,Title);
//----------------------------------------Wczytano okno tytulowe------------------------------------------------
    sf::SoundBuffer buffer;
    sf::Sound sound;
    buffer.loadFromFile("Sounds\\Otjanbird-Pt.-II.wav");
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.setVolume(20);
    Gate gate(window);
    PBar.Progress(15);
    std::vector<enemy*>chochol;
    PBar.Progress(25);
    std::vector<enemy*>mushroom;
    PBar.Progress(35);
    std::vector<heavy_enemy*>chocholP;
    PBar.Progress(45);
    std::vector<axe_enemy*>chocholA;
    PBar.Progress(55);
    std::vector<shovel_enemy*>chocholS;
    PBar.Progress(65);
    Level_Class Level(chochol,mushroom,chocholP,chocholA,chocholS,window);
    PBar.Progress(85);
    crafting Crafting(window,Config.DIM);
    PBar.Progress(90);
    prep_txt_items();
    vec.ini(&window);

    sf::Clock TabTime;
    sf::View Camera;
    Camera.zoom(Config.zoom);
    Camera.setCenter(18600,18600);
    background Background(window,"Textures//Grass.jpg","Textures//Sand.jpg");
    SoundEvent *Sound=new SoundEvent();
    character Pawel(window,"Textures//pawel.png");
    PBar.Progress(100);
    sound.play();
    double FTime;
    while(window.isOpen())
    {
        deltaTime.PrevFrameTime=deltaTime.TimeAsSec.getElapsedTime();
        deltaTime.TimeAsSec.restart();
        FTime=deltaTime.FrameTime();
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
                Camera.move((1.2f+BoostSpeed)*FTime,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Camera.getCenter().x>2500)
                Camera.move((-1.2f-BoostSpeed)*FTime,0);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Camera.getCenter().y>2500)
                Camera.move(0,(-1.2f-BoostSpeed)*FTime);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Camera.getCenter().y<34700)
                Camera.move(0,(1.2f+BoostSpeed)*FTime);
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
        if(Gate::show)
            gate.Update(Camera.getCenter());
        Level.Update(Camera.getCenter(),Sound,gate,FTime);
        Pawel.Update(Camera.getCenter(),FTime);
        if(Crafting.showInterface)
            Crafting.Update(Camera.getCenter());
        window.display();
    }
}
