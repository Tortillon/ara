#include "Figures.h"

void prepare_background_front_Fields()
{
    front_fields = new Pole [578];
    // Przygotowanie tablic

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            front_fields[i * board_size_y + j].owner = 0;
			set_figure_texture(&front_fields[i * board_size_y + j]);
            if(i%2==j%2)
            {
                background_fields[i][j].setTexture(Background);
                background_fields[i][j].setScale(sf::Vector2f(0.2, 0.2));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                background_fields[i][j].setPosition(sf::Vector2f(i*30,j*20));
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2, 0.2));
                front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*30,j*20));
            }
            else
            {
                background_fields[i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
            }
        }
    }

    for (int i = 0; i<8;++i)
    {
        for (int j = 0; j<8; ++j)
        {
            if((j-i)>=0)
            {
                background_fields[i][j-i].setPosition(sf::Vector2f(10000, 10000));
                background_fields[i][26+j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + j-i].setPosition(sf::Vector2f(10000, 10000));
                front_fields[i * board_size_y + 26+j].setPosition(sf::Vector2f(10000, 10000));
            }
            else
            {
                background_fields[9+i][j].setPosition(sf::Vector2f(10000, 10000));
                background_fields[9+i][32-j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + j].setPosition(sf::Vector2f(10000, 10000));
                front_fields[(9+i) * board_size_y + 32-j].setPosition(sf::Vector2f(10000, 10000));
            }
        }
    }

    for(int i = 8; i < 17; i ++)
    {
        background_fields[i][33].setPosition(sf::Vector2f(10000, 10000));
        front_fields[i * board_size_y + 33].setPosition(sf::Vector2f(10000, 10000));
    }
}
