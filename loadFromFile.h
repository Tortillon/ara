// ###Te biblioteki trzeb bedzie dolaczyc do ostatecznej wersji
#include "pole.h"
#include <fstream>
#include <cstdlib>
#include <string>
// ###

    int tura;
    int nrTura=1;
    int oldTura =1;
    int nrZmiany=1;
    int nrZmiany2=1;
    int baseX=8;
    int baseY=16;
    int basex=8;
    int basey=16;

int saveChosing(){
    std::fstream file;  // plik
    std::string line;

    file.open("saves/a.txt");
    getline(file, line);
    int returning = int(line[0])-('0');
    file.close();
    return returning;

}

int LoadSave(int save_number, Pole *fields) //0 -> dobrze, 1 -> cos sie powaznie zepsulo, 2 -> lekki blad
{
    int board_size_y = 34;
    std::string names[8] = {"pawn", "ghost", "tower", "cav", "mystery", "charge", "king", "notexist"};
    int returning = 0;

    /*
    sf::Texture texture_pawn;
    sf::Texture texture_ghost;
    sf::Texture texture_cav;
    sf::Texture texture_king;
    sf::Texture texture_tower;
    sf::Texture texture_charge;
    sf::Texture texture_mystery;
    sf::Texture texture_notexist;
    if (!texture_pawn.loadFromFile("img/pawn.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_ghost.loadFromFile("img/ghost.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_cav.loadFromFile("img/cav.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_king.loadFromFile("img/king.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_tower.loadFromFile("img/tower.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_charge.loadFromFile("img/charge.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_mystery.loadFromFile("img/mystery.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }
    if (!texture_notexist.loadFromFile("img/notexist.png"))
    {
        std::cout<<"NIE JEST DOBRZE!!!\n";
        system("PAUSE");
    }*/

    //Mam wszystkie textury

    std::fstream file;  // plik
    std::string line;

    if(save_number == 0)
    {
        file.open("saves/save0.txt", std::ios::in);
    }
    else if(save_number == 1)
    {
        file.open("saves/save1.txt", std::ios::in);
    }
    else if(save_number == 2)
    {
        file.open("saves/save2.txt", std::ios::in);
    }
    else if(save_number == 3)
    {
        file.open("saves/save3.txt", std::ios::in);
    }
    else if(save_number == 4)
    {
        file.open("saves/save4.txt", std::ios::in);
    }
    else if(save_number == 5)
    {
        file.open("Saves/save5.txt", std::ios::in);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y

    if(file.good() == false)
    {
        ms_error(84, "Load_From_File/LoadSave/file.good() == false", 1);
        file.close();
        return 1;
    }

    int length;

    std::string figure_name;
    int figure_x;
    int figure_y;
    int figure_owner;
    int j;

    // ###To jest pierwsza linia, trzeba ustawic aktualnego gracza
    getline(file, line);
    if(line.length() == 0)
    {
        ms_error(101, "Load_From_File/LoadSave/file is broken!!!", 1);
        file.close();
        return 1;
    }

    tura = int(line[0])-('0');
    // ###tu nie dzia³a zapisywanie tury

    bool good = 0;
    int i = 0;

    while(getline(file, line))
    {
        i++;
        length = line.length();

        figure_name = "";
        figure_x = 0;
        figure_y = 0;
        figure_owner = 0;

        j = 0;
        while((line[j] != ';') && (j < length))
        {
            figure_name += line[j];
            j++;
        }
        j++;
        while((line[j] != ';') && (j < length))
        {
            figure_x = figure_x * 10 + int(line[j]) - int('0');
            j++;
        }
        j++;
        while((line[j] != ';') && (j < length))
        {
            figure_y = figure_y * 10 + int(line[j]) - int('0');
            j++;
        }
        j++;
        figure_owner = int(line[j]) - int('0');

        // Sprawdzanie, czy w pliku sa dobre dane

        good = 0;
        for(int i = 0; i < 8; i ++)
        {
            if(figure_name == names[i])
            {
                good = 1;
                break;
            }
        }
        if((figure_x < 0) || (figure_x > 16) || (figure_y < 0) || (figure_y > 33))
        {
            good = 0;
        }

        /*if(!good)
        {
            char *intStr = itoa(i, intStr, 3);
            std::string str = std::string(intStr);
            std::string text = "Load_From_File/LoadSave/something wrong with " + str + " line of file";
            ms_error(164, text);
            returning = 2;
        }
        else
        {*/
            fields[figure_x * board_size_y + figure_y].owner = figure_owner;  // stawiam pionka
            fields[figure_x * board_size_y + figure_y].name = figure_name;    // stawiam pionka

        //}

        /*
        if(fields[figure_x * board_size_y + figure_y].name == "pawn")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_pawn);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "tower")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_tower);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "ghost")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_ghost);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "cav")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_cav);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "king")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_king);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "mystery")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_mystery);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "charge")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_charge);
        }
        else if(fields[figure_x * board_size_y + figure_y].name == "notexist")
        {
            fields[figure_x * board_size_y + figure_y].setTexture(texture_notexist);
        }
        fields[figure_x * board_size_y + figure_y].setScale(sf::Vector2f(0.2f, 0.2f));
        */

        // Mam textury i pozycje i skale
    }
    //std::cout<<"jest ok!\n";

    file.close();
    return returning;
}

int SaveGame(int save_number, Pole *fields) //0 -> dobrze, 1 -> cos sie powaznie zepsulo, 2 -> lekki blad
{
    int board_size_y = 34;
    int returning = 0;

    std::fstream file;  // plik

    if(save_number == 0)
    {
        file.open("saves/save0.txt", std::ios::out);
    }
    else if(save_number == 1)
    {
        file.open("saves/save1.txt", std::ios::out);
    }
    else if(save_number == 2)
    {
        file.open("saves/save2.txt", std::ios::out);
    }else if(save_number == 3)
    {
        file.open("saves/save3.txt", std::ios::out);
    }else if(save_number == 4)
    {
        file.open("saves/save4.txt", std::ios::out);
    }else if(save_number == 5)
    {
        file.open("saves/save5.txt", std::ios::out);
    }// ###W przypadku, gdy bedzie potrzebne wiecej zapisow, tu trzeba dodac odpowiednie elseif'y
    file<<tura<<"\n";


    for (int i = 0; i<17;++i)
    {
        for (int j = 0; j<33; ++j)
        {
            if(fields[i * board_size_y + j].name == "empty")
            {
                continue;
            }
            else
            {
                file<<fields[i * board_size_y + j].name<<";"<<i<<";"<<j<<";"<<fields[i * board_size_y + j].owner<<"\n";
            }
        }
    }

    file.close();
    return 0;
}
