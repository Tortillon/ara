#define _WIN32_WINNT 0x0500
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
//#include <windows.h>
#include "messages.h"
#include "wczytaj.h"
#include <unistd.h>


//MENU
int a;
sf::Vector2i mouse_position;
bool mouse_pressed = 0;

bool isLoadingSave=0;

int main()
{
    sf::Texture kursor;
    if (!kursor.loadFromFile("img/kursor.png"))
    {
        ms_error(26, "no kursor found", 1);
    }

    sf::Sprite Kursor;
    Kursor.setTexture(kursor);
    Kursor.setScale(0.1f, 0.1f);


    sf::Music music;
    if (!music.openFromFile("sounds/music.wav"))ms_error(24, "nie zaladowano music.wav");
    music.setVolume(10.f);
    music.play();


    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sounds/sound.wav"))
        ms_error(22, "nie zaladowano dzwieku");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(250.f);


    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    sf::RenderWindow window(sf::VideoMode(1000, 720), "A.R.A");
    window.setMouseCursorVisible(false);
    sf::Texture tlo;
    if (!tlo.loadFromFile("img/backgroundImage.png"))
    {
        ms_error(12, "nie zaladowano menuBackground", true);
    }
    sf::Sprite Tlo;
    Tlo.setTexture(tlo);

    sf::Texture loading;
    if (!loading.loadFromFile("img/loadingSave.png"))
    {
        ms_error(12, "nie zaladowano loadingSave", true);
    }
    sf::Sprite Loading;
    Loading.setTexture(loading);
    //window.draw(Loading);

    sf::Texture play;
    if (!play.loadFromFile("img/play.png"))
    {
        ms_error(19, "nie zaladowano play", true);
    }
    sf::Sprite Play;
    Play.setTexture(play);
    Play.setPosition(sf::Vector2f(300, 150));
    Play.setScale(sf::Vector2f(1.5, 1.5));


    sf::Texture exit;
    if (!exit.loadFromFile("img/exit.png"))
    {
        ms_error(24, "exit", true);
    }
    sf::Sprite Exit;
    Exit.setTexture(exit);
    Exit.setPosition(sf::Vector2f(400, 550));
    Exit.setScale(sf::Vector2f(0.6, 0.6));

    sf::Texture wczytaj;
    if (!wczytaj.loadFromFile("img/wczytaj.png"))
    {
        ms_error(30, "nie zaladowano edit", true);
    }
    sf::Sprite Wczytaj;
    Wczytaj.setTexture(wczytaj);
    Wczytaj.setPosition(sf::Vector2f(300, 350));
    Wczytaj.setScale(sf::Vector2f(1.2, 1.2));

    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                return 0;
            }
            if(event.type==sf::Event::KeyPressed){

                    if (event.key.code == sf::Keyboard::Escape&&isLoadingSave)isLoadingSave=0;;
            }
        }
        mouse_pressed = 0;

        mouse_position = sf::Mouse::getPosition(window);
        while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            mouse_position = sf::Mouse::getPosition(window);
            mouse_pressed = 1;
        }
        if(mouse_pressed&&!isLoadingSave){
            if(mouse_position.x>=300&&mouse_position.x<680&&mouse_position.y>150&&mouse_position.y<280){
                sound.play();
                music.stop();
                saveToFile(0);
                window.close();
                system("./sfml-app.o");

            }else if (mouse_position.x>=300&&mouse_position.x<707&&mouse_position.y>358&&mouse_position.y<473){
                sound.play();
                isLoadingSave=1;
                //usleep(microseconds);
            }else if(mouse_position.x>=400&&mouse_position.x<560&&mouse_position.y>550&&mouse_position.y<630){
                sound.play();
                music.stop();
                return 0;
                window.close();
                //return 0;
            }

        }
        //ladowanie save
        if(isLoadingSave){
            mouse_pressed=0;
            while(true){
                mouse_pressed = 0;
                window.draw(Loading);
                Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
                window.draw(Kursor);
                window.display();
                window.clear();
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    mouse_position = sf::Mouse::getPosition(window);
                    mouse_pressed = 1;
                }
                if(mouse_pressed){
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>30&&mouse_position.y<130){
                        sound.play();
                        saveToFile(1);
                        music.stop();
                        window.close();
                        system("./sfml-app.o");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>170&&mouse_position.y<290){
                        sound.play();
                        saveToFile(2);
                        music.stop();
                        window.close();
                        system("./sfml-app.o");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>320&&mouse_position.y<430){
                        sound.play();
                        saveToFile(3);
                        music.stop();
                        window.close();
                        system("./sfml-app.o");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>470&&mouse_position.y<570){
                        sound.play();
                        saveToFile(4);
                        music.stop();
                        window.close();
                        system("./sfml-app.o");
                    }
                    if(mouse_position.x>=140&&mouse_position.x<860&&mouse_position.y>610&&mouse_position.y<710){
                       sound.play();
                       saveToFile(5);
                       music.stop();
                       window.close();
                       system("./sfml-app.o");
                    }
                }
            }
        }






        window.draw(Tlo);
        window.draw(Wczytaj);
        window.draw(Play);
        window.draw(Exit);
        Kursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        window.draw(Kursor);
        window.display();
        window.clear();


        //window.clear();
        //std::cin>>a;
        /*if(a==1){
            window.close();
            system("..\\..\\..\\bin\\Debug\\ara.exe");

        }*/
    }
}
