#include "pole.h"

sf::Texture Background;
sf::Texture texture_pawn;
sf::Texture texture_ghost;
sf::Texture texture_cav;
sf::Texture texture_king;
sf::Texture texture_tower;
sf::Texture texture_charge;
sf::Texture texture_mystery;
sf::Texture texture_notexist;
sf::Texture texture_nothing;

void loadTexture()
{
    //wczytuje teksturki pionkow i tla
	if (!Background.loadFromFile("img/dupa.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_pawn.loadFromFile("img/pawn.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_ghost.loadFromFile("img/ghost.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_cav.loadFromFile("img/cav.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_king.loadFromFile("img/king.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_tower.loadFromFile("img/tower.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_charge.loadFromFile("img/charge.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_mystery.loadFromFile("img/mystery.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_notexist.loadFromFile("img/notexist.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
	if (!texture_nothing.loadFromFile("img/nothing.png"))
	{
		ms_error(666, "Header.h", 1);
		system("PAUSE");
	}
}

void set_figure_texture(Pole *field)  // nie jestem pewien czy powinny byc tu te '*' to zostawie wam do sprawdzenia...
{
	if(*field.name == "pawn")
	{
		*field.setTexture(texture_pawn);
	}
	else if(*field.name == "tower")
	{
		*field.setTexture(texture_tower);
	}
	else if(*field.name == "ghost")
	{
		*field.setTexture(texture_ghost);
	}
	else if(*field.name == "cav")
	{
		*field.setTexture(texture_cav);
	}
	else if(*field.name == "king")
	{
		*field.setTexture(texture_king);
	}
	else if(*field.name == "mystery")
	{
		*field.setTexture(texture_mystery);
	}
	else if(*field.name == "charge")
	{
		*field.setTexture(texture_charge);
	}
	else if(*field.name == "notexist")
	{
		*field.setTexture(texture_notexist);
	}
	else if(*field.name == "empty")
	{
		*field.setTexture(texture_nothing);
	}
}