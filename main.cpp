#define _WIN32_WINNT 0x0500

bool click=0;


#include <sstream>
#include "figures.h"
#include "header.h"
#include "fields.h"
#include <math.h>
#include "highlight.h"
#include "AI.h"

bool ai=0;
bool firstMenu=1;
bool firstLoad=0;
bool ruch=1;

int zakazaneX;
int zakazaneY;

int main()
{
    srand(time(NULL));
    //sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    window.setMouseCursorVisible(false);
    sf::Clock minutes;
    sf::Clock seconds;
    sf::Music music;

    if (!music.openFromFile("sounds/music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(10.f);

    music.play();
    music.setLoop(true);
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds/sound.wav"))
        ms_error(22, "nie zaladowano dzwieku");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(150.f);




//=================================T£O================================================//



    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        scale=0.35*sf::VideoMode::getDesktopMode().height/1080; //uzależnic od sizePlanszyPrzed
        posuniecieX=0;
        posuniecieY=0;//paweł da rade!
    }else{
        scale=0.397*sf::VideoMode::getDesktopMode().width/1080; //uzależnić od size planszzyPrzed
        posuniecieX=0;
        posuniecieY=0;
    }



    if(nrTura==1){
        background_fields[baseX][baseY].setPosition(1000,1000);
        front_fields[baseX*34+baseY].name="notexist";
        front_fields[baseX*34+baseY].owner=0;
        baseX+=1;
        baseY-=1;
        basex-=1;
        basey+=1;
    }

    loadFiguresTexture();
    loadSettings();
    loadMenuTexture();
    backgroundFields();

    frontFields();

    float skalaX = float(sf::VideoMode::getDesktopMode().width)/backroundImage.getSize().x;
    float skalaY = float(sf::VideoMode::getDesktopMode().height)/backroundImage.getSize().y;

    int czteresci =texture_kingD.getSize().x*scale;
    int dwajscia = czteresci/2;



    sf::Sprite SbackroundImage;
    SbackroundImage.setTexture(backroundImage);
    if(sf::VideoMode::getDesktopMode().width>sf::VideoMode::getDesktopMode().height){
        SbackroundImage.setScale(skalaX, skalaX);
        SbackroundImage.setPosition(0, float(-(backroundImage.getSize().y*skalaX - sf::VideoMode::getDesktopMode().height)/2));
    }else{
        SbackroundImage.setScale(skalaY, skalaY);
        SbackroundImage.setPosition((float(sf::VideoMode::getDesktopMode().width)-backroundImage.getSize().x*skalaY)/2 ,0);
    }


    sf::Color basicColor = background_fields[8][28].getColor();



    //====================================================================PETLA GLOWNA================================================================//
    //===================================================================PETLA GLOWNA=============================================================//
    //=====================================================================PETLA GLOWNA===========================================================//
while(true){
    while (window.isOpen()&&firstMenu)
    {
        float scaleMenuX = 1920/ sf::VideoMode::getDesktopMode().width;
        float scaleMenuY = 1080/ sf::VideoMode::getDesktopMode().height;
        //std::cout<<"x: "<<sf::Mouse::getPosition().x <<"y: "<<sf::Mouse::getPosition().y<<"\n";
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Mouse::getPosition().x>340*scaleMenuX&&sf::Mouse::getPosition().x<700*scaleMenuX&&
           sf::Mouse::getPosition().y>400*scaleMenuY&&sf::Mouse::getPosition().y<560*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                firstMenu=0;
                }
                PlaySprite.setColor(sf::Color::White);
        }else PlaySprite.setColor(sf::Color(255, 255, 255, 200));



        if(sf::Mouse::getPosition().x>1095*scaleMenuX&&sf::Mouse::getPosition().x<1655*scaleMenuX&&
           sf::Mouse::getPosition().y>440*scaleMenuY&&sf::Mouse::getPosition().y<550*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    firstMenu=0;
                    firstLoad=1;
                }
                LoadGameSprite.setColor(sf::Color::White);
        }else LoadGameSprite.setColor(sf::Color(255, 255, 255, 200));



        if(sf::Mouse::getPosition().x>500*scaleMenuX&&sf::Mouse::getPosition().x<830*scaleMenuX&&
           sf::Mouse::getPosition().y>635*scaleMenuY&&sf::Mouse::getPosition().y<820*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                }
                TutorialSprite.setColor(sf::Color::White);
        }else TutorialSprite.setColor(sf::Color(255, 255, 255, 200));


        if(sf::Mouse::getPosition().x>1075*scaleMenuX&&sf::Mouse::getPosition().x<1400*scaleMenuX&&
           sf::Mouse::getPosition().y>635*scaleMenuY&&sf::Mouse::getPosition().y<840*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                }
                OptionsSprite.setColor(sf::Color::White);
        }else OptionsSprite.setColor(sf::Color(255, 255, 255, 200));

        if(sf::Mouse::getPosition().x>55*scaleMenuX&&sf::Mouse::getPosition().x<360*scaleMenuX&&
           sf::Mouse::getPosition().y>918*scaleMenuY&&sf::Mouse::getPosition().y<1010*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                }
                AutorsSprite.setColor(sf::Color::White);
        }else AutorsSprite.setColor(sf::Color(255, 255, 255, 200));

        if(sf::Mouse::getPosition().x>1680*scaleMenuX&&sf::Mouse::getPosition().x<1855*scaleMenuX&&
           sf::Mouse::getPosition().y>944*scaleMenuY&&sf::Mouse::getPosition().y<1018*scaleMenuY){
               if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    return 0;
                }
                ExitSprite.setColor(sf::Color::White);
        }else ExitSprite.setColor(sf::Color(255, 255, 255, 200));



        Kursor.setTexture(kursor);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        //std::cout<<Kursor.getPosition().x<<"x"<<Kursor.getPosition().y<<"\n";
        window.draw(menu2Sprite);
        window.draw(ARASprite);
        window.draw(OptionsSprite);
        window.draw(ExitSprite);
        window.draw(AutorsSprite);
        window.draw(LoadGameSprite);
        window.draw(PlaySprite);
        window.draw(TutorialSprite);
        window.draw(Kursor);


        window.display();
        window.clear();
    }

    while (window.isOpen()&&!firstMenu && firstLoad)
    {
        float scaleMenuX = 1920/ (menu1.getSize().x * menu1Sprite.getScale().x  );
        float scaleMenuY = 1080/ (menu1.getSize().y * menu1Sprite.getScale().y  );
        //std::cout<<"x: "<<sf::Mouse::getPosition().x <<"y: "<<sf::Mouse::getPosition().y<<"\n";
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        Kursor.setTexture(kursor);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(savePlusSubSprite);
        window.draw(saveBookSprite);
        window.draw(saveslot1Sprite);
        window.draw(saveslot2Sprite);
        window.draw(saveslot3Sprite);
        window.draw(saveslot4Sprite);
        window.draw(saveslot5Sprite);
        window.draw(saveslot6Sprite);
        window.draw(Kursor);


        window.display();
        window.clear();
    }

    bool s=1;

    while (window.isOpen()&&!firstMenu && !firstLoad)
    {
        if(s){
            s=0;
            LoadSave(saveChosing(), front_fields);
        }

        Kursor.setTexture(kursor);
        mousePointing = 0;
        mouse_pressed = 0;
        window.draw(SbackroundImage);
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:

                    window.close();
                    music.stop();
                    return 0;
                    break;
                case sf::Event::Resized:
                    //ResizeView(window, view);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape&&isMenu)isMenu=0;
                    else if(event.key.code == sf::Keyboard::Escape&&isSaving){
                        isMenu=1;
                        isSaving=0;
                    }else if(event.key.code == sf::Keyboard::Escape)isMenu=1;
                    else if(event.key.code == sf::Keyboard::S&&isSaving){
                        isMenu=1;
                        isSaving=0;
                    }else if(event.key.code == sf::Keyboard::S&&!isSaving){
                        isSaving=1;
                        isMenu=0;
                    }
                break;
            }

        }

        //consoleHiding();


//=========================Znikanie mapy=====================================//

        if(oldTura+coIleTurMaSieZapadac<=nrTura){

            background_fields[baseX][baseY].setPosition(1000,1000);
            front_fields[baseX*34+baseY].name="notexist";
            window.draw(front_fields[baseX*34+baseY]);
            front_fields[baseX*34+baseY].owner=0;
            front_fields[baseX*34+baseY].setTexture(texture_notexist);
            background_fields[basex][basey].setPosition(1000,1000);
            front_fields[basex*34+basey].name="notexist";
            window.draw(front_fields[basex*34+basey]);
            front_fields[basex*34+basey].owner=0;
            front_fields[basex*34+basey].setTexture(texture_notexist);
            algorytmBase();



            oldTura=nrTura;

            nrZmiany++;

        }

        mouse_position = sf::Mouse::getPosition(window);
        if(!isMenu&!isSaving){
            for(int i = 0; i < 17; i ++)
            {
                for(int j = 0; j < 34; j ++)
                {
                    if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < dwajscia*dwajscia)
                    {
                        if(!click){
                                if(front_fields[i*34+j].owner==1)background_fields[i][j].setColor(sf::Color(175,210,255,150));
                                else if (front_fields[i*34+j].owner==2) background_fields[i][j].setColor(sf::Color(255,220,175,140));
                                else background_fields[i][j].setColor(sf::Color(255,255,255,220));
                        }else{

                            if(front_fields[i*34+j].owner==opponentOwner){
                               if (!kursor.loadFromFile("graphics/rzeczy/kursorKlik.png"))ms_error(216, "no kursor found", 1);
                            }else{
                                if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
                                    {
                                    ms_error(26, "no kursor found", 1);
                                    }
                            }


                        }
                    }
                    else if((front_fields[i * board_size_y + j].name != "empty"))
                    {
                        if(front_fields[i * board_size_y + j].owner == 1)
                        {
                            if(!click)background_fields[i][j].setColor(bColor);
                        }
                        else if(front_fields[i * board_size_y + j].owner == 2)
                        {
                            if(!click){
                                    background_fields[i][j].setColor(yColor);
                            }
                        }else if(front_fields[i * board_size_y + j].name == "notexist"){
                            if(!click)background_fields[i][j].setTexture(texture_notexist);
                        }

                    }else if(!click){
                        sf::Color a= background_fields[i][j].getColor();
                        if(a!=sf::Color::Cyan)background_fields[i][j].setColor(basicColor);


                    if(background_fields[baseX][baseY].typK==1)background_fields[baseX][baseY].setTexture(BackgroundBroken);
                    else if(background_fields[baseX][baseY].typK==2) background_fields[baseX][baseY].setTexture(BackgroundBroken2);
                    else background_fields[baseX][baseY].setTexture(BackgroundBroken3);

                    if(background_fields[basex][basey].typK==1)background_fields[basex][basey].setTexture(BackgroundBroken);
                    else if(background_fields[basex][basey].typK==2)background_fields[basex][basey].setTexture(BackgroundBroken2);
                    else background_fields[basex][basey].setTexture(BackgroundBroken3);
                    }
                }
            }
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouse_position = sf::Mouse::getPosition(window);
                mouse_pressed = 1;
            }

            if((actual_mode == "play") && (mouse_pressed||(ai&&tura==1)))
            {
                if(!ai||tura==2){
                    if((figure_x == 0) && (figure_y == 0))
                    {
                        for(int i = 0; i < 17; i ++)
                        {
                            for(int j = 0; j < 34; j ++)
                            {
                                if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2))
                                {
                                    figure_x = i;
                                    figure_y = j;
                                    front_fields[i*34+j].owner==1?background_fields[i][j].setColor(sf::Color(175,210,255,150)):background_fields[i][j].setColor(sf::Color(255,220,175,140));
                                    if((front_fields[figure_x * 34 + figure_y].name == "empty"))
                                    {
                                        figure_x = 0;
                                        figure_y = 0;
                                    }else if(front_fields[figure_x*34+figure_y].owner==tura && (figure_x!=zakazaneX || figure_y!=zakazaneY)){
                                        click=1;

                                        mouse_position = sf::Mouse::getPosition(window);
                                        (front_fields[figure_x* 34 + figure_y].owner == 1)?opponentOwner = 2:opponentOwner = 1;
                                        //=======================================[highLight]================================
                                        if(!highlight(figure_x, figure_y))ms_error(279, "cos poszlo nie tak z highlightem");
                                        //========================================highlight=========================================================
                                    }
                                    else{
                                        figure_x=0;
                                        figure_y=0;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        for(int i = 0; i < 17; i ++)
                        {
                            for(int j = 0; j < 34; j ++)
                            {
                                if(pow(mouse_position.x - dwajscia - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - dwajscia - background_fields[i][j].getPosition().y, 2) < pow(dwajscia,2))
                                {

                                    target_x = i;
                                    target_y = j;
                                    if(front_fields[34*figure_x+figure_y].owner)
                                    {
                                        if(action(front_fields, figure_x, figure_y, target_x, target_y))
                                        {

                                            if(tura == 1 && ruch==0) {
                                                tura = 2;
                                                ruch=1;
                                                nrTura++;
                                                zakazaneX=0;
                                                zakazaneY=0;
                                            }
                                            else if(tura == 1 && ruch==1){
                                                ruch = 0;
                                                zakazaneX=target_x;
                                                zakazaneY=target_y;
                                            }
                                            else if(tura == 2 && ruch==0){
                                                tura = 1;
                                                ruch=1;
                                                nrTura++;
                                                zakazaneX=0;
                                                zakazaneY=0;
                                            }
                                            else if(tura == 2 && ruch==1) {
                                                    ruch = 0;
                                                zakazaneX=target_x;
                                                zakazaneY=target_y;
                                            }
                                            sound.play();
                                            click=0;

                                            front_fields[target_x*34+target_y].setTexture(*front_fields[figure_x*34+figure_y].getTexture());
                                            front_fields[figure_x*34+figure_y].setTexture(texture_nothing);

                                            window.draw(front_fields[target_x*34+target_y]);
                                            window.draw(front_fields[figure_x*34+figure_y]);
                                            for(int i = 0; i < 17; i++){

                                                for (int j = 0; j< 34; j++){
                                                    frontFields();
                                                    window.draw(front_fields[i*34+j]);
                                                    window.draw(front_fields[i*34+j]);

                                                }
                                            }


                                            if (!kursor.loadFromFile("graphics/rzeczy/kursorDuzy.png"))
                                            {
                                                ms_error(26, "graphics/rzeczy/kursorDuzy.png", 1);
                                            }
                                        }
                                    }
                                    else ms_message("to nie twoja tura dzbanie");
                                    figure_x = 0;
                                    figure_y = 0;
                                }
                            }
                        }
                    }
                }else if(!win){
                    if(!AI(front_fields));
                    std::cout<<"doszlem\n";
                    if(!action(front_fields, aiFX, aiFY, aiTX, aiTY));
                    mouse_pressed=0;
                    if(tura == 1) tura = 2;
                    else tura = 1;
                    nrTura++;
                    sound.play();
                    click=0;
                }
            }
        }

        //=======================Plansza menu==========================//
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))clickInSaving=0;

        if(isMenu&&!clickInSaving){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>110&&mouse_position.y<180){
                    isMenu=0;
                    sound.play();
                }else if(mouse_position.x>=230&mouse_position.x<=510&&mouse_position.y>215&&mouse_position.y<290){
                    sound.play();
                    isMenu=0;
                    isSaving=1;
                    clickInMenu=1;
                }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>320&&mouse_position.y<380){  //działa tylko z execa (wraca do menu){
                    sound.play();
                    window.close();
                    music.stop();
                    //system("./araMenu/sfml-app.o");  //działa tylko z execa (wraca do menu
                    system("ara.exe");  //działa tylko z execa (wraca do menu
                    return 0;
                }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>430&&mouse_position.y<490){
                    sound.play();
                    music.stop();

                    window.close();
                    return 0;
                }
            }
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))clickInMenu=0;

        if(isSaving&&!clickInMenu){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>50&&mouse_position.y<120){
                    SaveGame(1, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>150&&mouse_position.y<230){
                    SaveGame(2, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>270&&mouse_position.y<360){
                    SaveGame(3, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>380&&mouse_position.y<450){
                    SaveGame(4, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>480&&mouse_position.y<560){
                    SaveGame(5, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                    clickInSaving=1;
                }
            }
        }




            for (int i = 0; i<17; ++i)
            {
                for (int j = 0; j<33; ++j)
                {
                    window.draw(background_fields[i][j]);
                    window.draw(front_fields[i * board_size_y + j]);
                }
            }
            sf::Texture winTexture;
            // !!!!!!!!!!!!!!!!!Napisac ekran wygranej !!!!!!!!!!!!!!!!!!//
            if(win){

                if(tura==1){
                    if (!winTexture.loadFromFile("img/winDolny.png"))
                    {
                    ms_error(230, "main.cpp no file winDolny.png, 1");
                    }
                }else{
                    if (!winTexture.loadFromFile("img/winGorny.png"))
                    {
                        ms_error(230, "main.cpp no file winGorny.png", true);
                    }

                }
                WinTexture.setTexture(winTexture);
                WinTexture.setPosition(sf::Vector2f(0,0));
                WinTexture.setScale(float(sf::VideoMode::getDesktopMode().width)/winTexture.getSize().x, float(sf::VideoMode::getDesktopMode().height)/winTexture.getSize().y);
            }

            unsigned int time;
            unsigned int minute;

            if(!isMenu){
                time = seconds.getElapsedTime().asSeconds();
                minute = minutes.getElapsedTime().asSeconds()/60;
            }
        std::ostringstream ss;
        ss.clear();
        (time<10)?ss << "Czas: " <<minute<<":0"<<time:ss << "Czas: " <<minute<<":"<<time;


        sf::Text clock;
        clock.setPosition(sf::Vector2f(1625, 325));
        clock.setFont(font);
        clock.setCharacterSize(20);
        clock.setStyle(sf::Text::Regular);
        clock.setString(ss.str());

        std::ostringstream ss1;
        if(tura==2)ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Dolny";
        else ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Gorny";

        sf::Text turn;
        turn.setPosition(sf::Vector2f(1635, 275));
        turn.setFont(font);
        turn.setCharacterSize(20);
        turn.setStyle(sf::Text::Regular);
        turn.setString(ss1.str());

         if(int(time)>59)
        {
            seconds.restart();
        }
        //window.draw(klik);
        window.draw(clock);
        window.draw(turn);
        window.draw(WinTexture);
        //view.setCenter(sf::Vector2f(360.0f, 360.0f));
        //window.setView(view);
        if(isMenu)window.draw(Menu);
        if(isSaving)window.draw(Save);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(Kursor);
        //std::cout<<Kursor.getPosition().x<<"x"<<Kursor.getPosition().y<<"\n";
        window.display();
        window.clear();

        if(win==1){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)||sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    music.stop();
                    window.close();
                    system("ara.exe");  //działa tylko z execa (wraca do menu
                    //system("./araMenu/sfml-app.o");  //działa tylko z execa (wraca do menu)
                }
        }


    }
}
    return 0;
}
