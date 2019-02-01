#define _WIN32_WINNT 0x0500

bool click=0;

#include <sstream>
#include "Figures.h"
#include "Header.h"
#include "fields.h"
#include "mapRemoving.h"
#include <math.h>
#include "highlight.h"
#include "AI.h"

bool ai=0;




int main()
{
    sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    window.setMouseCursorVisible(false);
    sf::Clock minutes;
    sf::Clock seconds;
    sf::Music music;
    if (!music.openFromFile("sounds\\music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(20.f);
    music.play();
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds\\sound.wav"))
        ms_error(22, "nie zaladowano dzwieku");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(250.f);

    sf::Texture kursor;
    if (!kursor.loadFromFile("img/kursor.png"))
    {
        ms_error(26, "no kursor found", 1);
    }

    Kursor.setTexture(kursor);
    Kursor.setScale(0.1f, 0.1f);







//=================================T£O================================================//
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }
    sf::Font font;
    if (!font.loadFromFile("fonts/arial.ttf"))
    {
        ms_error(54, "nie zaladowano czcionki");
    }


    loadTexture();

    backgroundFields();

    Pole klik;
    klik.setPosition(sf::Vector2f(650, 350));
    klik.setScale(sf::Vector2f(0.2, 0.2));
    klik.setTexture(Background);
    klik.setColor(sf::Color::Red);

    LoadSave(saveChosing(), front_fields);
    //std::cout<<tura<<"\n";
    frontFields();

    if(nrTura==1){
        background_fields[baseX][baseY].setPosition(1000,1000);
        front_fields[baseX*34+baseY].name="notexist";
        front_fields[baseX*34+baseY].owner=0;
        baseX+=1;
        baseY-=1;
        basex-=1;
        basey+=1;
        background_fields[basex][basey].setTexture(Background);
        background_fields[baseX][baseY].setTexture(Background);
        background_fields[baseX][baseY].setColor(sf::Color::Cyan);
        background_fields[basex][basey].setColor(sf::Color::Cyan);
    }

    for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                background_fields[i][j].setScale(0.222f, 0.222f);
                sf::Color a= background_fields[i][j].getColor();
                if(front_fields[i*34+j].name!="notexist"&&a!=sf::Color::Cyan)background_fields[i][j].setTexture(Background);

                //else background_fields[i][j].setTexture(texture_notexist);
            }
        }
    while (window.isOpen())
    {
        Kursor.setTexture(kursor);
        Kursor.setScale(0.1f, 0.1f);
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
                    ResizeView(window, view);
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

        if(oldTura+coIleTurMaSieZapadac-1<nrTura){
            //std::cout<<nrZmiany<<"\n";
            //std::cout<<nrZmiany2<<"\n";

            background_fields[baseX][baseY].setPosition(1000,1000);
            front_fields[baseX*34+baseY].name="notexist";
            front_fields[baseX*34+baseY].owner=0;
            background_fields[basex][basey].setPosition(1000,1000);
            front_fields[basex*34+basey].name="notexist";
            front_fields[basex*34+basey].owner=0;
            algorytmBase();



            oldTura=nrTura;

            nrZmiany++;
            //std::cout<<nrZmiany-2<<std::endl;

        }
//==============================Aktualizacja tekstur=====================================//
        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                if(front_fields[i * board_size_y + j].name == "pawn")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_pawn);
                }
                else if(front_fields[i * board_size_y + j].name == "tower")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_tower);
                }
                else if(front_fields[i * board_size_y + j].name == "ghost")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_ghost);
                }
                else if(front_fields[i * board_size_y + j].name == "cav")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_cav);
                }
                else if(front_fields[i * board_size_y + j].name == "king")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_king);
                }
                else if(front_fields[i * board_size_y + j].name == "mystery")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_mystery);
                }
                else if(front_fields[i * board_size_y + j].name == "charge")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_charge);
                }
                else if(front_fields[i * board_size_y + j].name == "notexist")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_notexist);
                }
                else if(front_fields[i * board_size_y + j].name == "empty")
                {
                    front_fields[i * board_size_y + j].setTexture(texture_nothing);
                }

            }
        }



//==============================Zabawa z myszka==========================================//
       mouse_pressed = 0;

        mouse_position = sf::Mouse::getPosition(window);
        if(!isMenu&!isSaving){
            for(int i = 0; i < 17; i ++)
            {
                for(int j = 0; j < 34; j ++)
                {
                    if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                    {
                        if(!click)background_fields[i][j].setColor(sf::Color::Magenta);
                        else{

                            if(front_fields[i*34+j].owner==opponentOwner&&canAttack(front_fields,figure_x,figure_y, i, j)){
                                if(front_fields[figure_x*34+figure_y].name=="tower"){ if(!kursor.loadFromFile("img/kursorC.png")) ms_error(26, "no kursor found", 1);}
                                else{ if (!kursor.loadFromFile("img/kursorF.png"))ms_error(216, "no kursor found", 1);}
                            }else{

                                if (!kursor.loadFromFile("img/kursor.png")) ms_error(26, "no kursor found", 1);
                            }


                        }
                    }
                    else if((front_fields[i * board_size_y + j].name != "empty"))
                    {
                        if(front_fields[i * board_size_y + j].owner == 1)
                        {
                            if(!click)background_fields[i][j].setColor(sf::Color::Yellow);
                        }
                        else
                        {
                            if(!click)background_fields[i][j].setColor(sf::Color::Blue);
                        }

                    }else if(!click){
                        sf::Color a= background_fields[i][j].getColor();
                        if(a!=sf::Color::Cyan)background_fields[i][j].setColor(sf::Color::White);



                    background_fields[baseX][baseY].setColor(sf::Color::Cyan);
                    background_fields[basex][basey].setColor(sf::Color::Cyan);

                    }
                }
            }


            while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouse_position = sf::Mouse::getPosition(window);
                mouse_pressed = 1;
            }
            if((pow(mouse_position.x - 20 - klik.getPosition().x, 2) + pow(mouse_position.y - 20 - klik.getPosition().y, 2) < 400) && mouse_pressed)
            {
                if(actual_mode == "edit")
                {
                    actual_mode = "play";
                    std::cout<<"Zmieniono tryb na \"play\"\n";
                }
                else
                {
                    actual_mode = "edit";
                    std::cout<<"Zmieniono tryb na \"edit\"\n";
                    std::cin>>actual_name;
                    std::cin>>actual_owner;
                }
            }
            else if((actual_mode == "edit") && mouse_pressed)
            {
                for(int i = 0; i < 17; i ++)
                {
                    for(int j = 0; j < 34; j ++)
                    {
                        if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                        {
                            front_fields[i * board_size_y + j].name = actual_name;
                            front_fields[i * board_size_y + j].owner = actual_owner;
                            i = 16;
                            j = 33;
                        }
                    }
                }
            }
            else if((actual_mode == "play") && (mouse_pressed||(ai&&tura==1)))
            {
                if(!ai||tura==2){
                    if((figure_x == 0) && (figure_y == 0))
                    {
                        for(int i = 0; i < 17; i ++)
                        {
                            for(int j = 0; j < 34; j ++)
                            {
                                if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                                {
                                    figure_x = i;
                                    figure_y = j;
                                    if((front_fields[figure_x * 34 + figure_y].name == "empty"))
                                    {
                                        figure_x = 0;
                                        figure_y = 0;
                                    }else if(front_fields[figure_x*34+figure_y].owner==tura){
                                        click=1;

                                        mouse_position = sf::Mouse::getPosition(window);
                                        if(front_fields[figure_x*34+figure_y].owner==2)opponentOwner=1;
                                        else if(front_fields[figure_x*34+figure_y].owner==1)opponentOwner=2;
                                        //======================================================[highLight]================================
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
                                if(pow(mouse_position.x - 20 - background_fields[i][j].getPosition().x, 2) + pow(mouse_position.y - 20 - background_fields[i][j].getPosition().y, 2) < 400)
                                {
                                    target_x = i;
                                    target_y = j;
                                    if(front_fields[34*figure_x+figure_y].owner == tura)
                                    {
                                        if(Action(front_fields, figure_x, figure_y, target_x, target_y))
                                        {
                                            if(tura == 1) tura = 2;
                                            else tura = 1;
                                            nrTura++;
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

                                                    if((front_fields[i * board_size_y + j].name != "empty"))
                                                    {
                                                        if(front_fields[i * board_size_y + j].owner == 1)
                                                        {
                                                            background_fields[i][j].setColor(sf::Color::Yellow);
                                                        }
                                                        else
                                                        {
                                                            background_fields[i][j].setColor(sf::Color::Blue);
                                                        }

                                                    }else{
                                                        sf::Color a= background_fields[i][j].getColor();
                                                        if(a!=sf::Color::Cyan)background_fields[i][j].setColor(sf::Color::White);
                                                    }



                                                }
                                            }

                                        }
                                        if (!kursor.loadFromFile("img/kursor.png"))
                                        {
                                            ms_error(26, "no kursor found", 1);
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
                    if(!Action(front_fields, aiFX, aiFY, aiTX, aiTY));
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

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

            if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>110&&mouse_position.y<180){
                isMenu=0;
            }else if(mouse_position.x>=230&mouse_position.x<=510&&mouse_position.y>215&&mouse_position.y<290){
                isMenu=0;
                isSaving=1;
            }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>320&&mouse_position.y<380){  //działa tylko z execa (wraca do menu){
                window.close();
                music.stop();
                system("ara.exe");  //działa tylko z execa (wraca do menu
            }else if(mouse_position.x>=250&mouse_position.x<=500&&mouse_position.y>430&&mouse_position.y<490){
                music.stop();
                window.close();




            }

        }

        if(isSaving){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>50&&mouse_position.y<120){
                    SaveGame(1, front_fields);
                    std::cout<<"lolo\n";
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>150&&mouse_position.y<230){
                    SaveGame(2, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                }
                else if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>270&&mouse_position.y<360){
                    SaveGame(3, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>380&&mouse_position.y<450){
                    SaveGame(4, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
                }
                if(mouse_position.x>=190&mouse_position.x<=590&&mouse_position.y>480&&mouse_position.y<560){
                    SaveGame(5, front_fields);
                    isSaving=0;
                    isMenu=1;
                    sound.play();
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
            }


            int time = seconds.getElapsedTime().asSeconds();
            int minute = minutes.getElapsedTime().asSeconds()/60;

        std::ostringstream ss;
        ss.clear();
        (time<10)?ss << "Czas: " <<minute<<":0"<<time:ss << "Czas: " <<minute<<":"<<time;



        sf::Text clock;
        clock.setPosition(sf::Vector2f(625, 325));
        clock.setFont(font);
        clock.setCharacterSize(20);
        clock.setStyle(sf::Text::Regular);
        clock.setString(ss.str());

        std::ostringstream ss1;
        if(tura==2)ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Dolny";
        else ss1<<" Tura: "<<nrTura<<std::endl<<"Gracz: Gorny";

        sf::Text turn;
        turn.setPosition(sf::Vector2f(635, 275));
        turn.setFont(font);
        turn.setCharacterSize(20);
        turn.setStyle(sf::Text::Regular);
        turn.setString(ss1.str());

         if(int(time)>59)
        {
            seconds.restart();
        }
        if(minute!=0&&minute%3==0)music.play();
        //window.draw(klik);
        window.draw(clock);
        window.draw(turn);
        sf::Sprite Win;
        Win.setTexture(winTexture);
        Win.setPosition(sf::Vector2f(0,0));
        window.draw(Win);
        view.setCenter(sf::Vector2f(360.0f, 360.0f));
        window.setView(view);
        if(isMenu)window.draw(Menu);
        if(isSaving)window.draw(Save);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(Kursor);
        window.display();
        window.clear();

        if(win==1){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)||sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                    music.stop();
                    window.close();
                    system("ara.exe");  //działa tylko z execa (wraca do menu)
                }
        }


    }

    return 0;
}
