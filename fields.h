void backgroundFields()
{
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {

    }


    front_fields = new Pole [578];
    // Przygotowanie tablic

    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            front_fields[i * board_size_y + j].name = "empty";
            front_fields[i * board_size_y + j].owner = 0;
            if(i%2==j%2)
            {
                background_fields[i][j].setTexture(Background);
                background_fields[i][j].setScale(sf::Vector2f(0.2, 0.2));
                background_fields[i][j].setOrigin(sf::Vector2f(0.1, 0.1));
                background_fields[i][j].setPosition(sf::Vector2f(i*35,j*20));
                front_fields[i * board_size_y + j].setScale(sf::Vector2f(0.2, 0.2));
                front_fields[i * board_size_y + j].setOrigin(sf::Vector2f(0.1, 0.1));
                front_fields[i * board_size_y + j].setPosition(sf::Vector2f(i*35,j*20));
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

void frontFields(){
    sf::Texture Background;
    /*if (!Background.loadFromFile("img//dupa.png"))
    {

    }*/

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
            background_fields[i][j].setTexture(Background);
        }
    }
}
