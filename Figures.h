#include "Load_From_File.h"
bool win=0;
/*
    Pionek          - pawn
    Duch            - ghost
    Kawaleria       - cav
    Król            - king
    Wie¿a           - tower
    Szar¿a          - charge
    Zagadka         - mystery

    pole przepaœci  - notexist
    pole puste      - empty
*/

int abs(int x)
{
    return x > 0 ? x: -x;
}

bool CanMove(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }

    if(board[x][y].name=="charge")
    {
        if((y == targetY) && (abs(targetX - x) == 2)) return 1;
        if(x == targetX)
        {
            if(y > targetY)
            {
                for(int i = targetY + 2; i < y; i += 2)
                {
                    if((board[x][i].name == "empty") || (board[x][i].owner == board[x][y].owner))
                    {
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
            else
            {
                for(int i = y + 2; i < targetY; i += 2)
                {
                    if((board[x][i].name == "empty") || (board[x][i].owner == board[x][y].owner))
                    {
                        continue;
                    }
                    return 0;
                }
                return 1;
            }
        }
    }

    if(board[x][y].name=="tower")
    {
        if(targetX==x)
        {
            if(abs(targetY-y) == 2) return 1;
            if(abs(targetY-y) == 4)
            {
                if(board[x][(targetY + y) / 2].name == "empty") return 1;
                else return 0;
            }
        }
        if(abs(targetX-x)==1 && abs(targetY-y)==1) return 1;
        if(abs(targetX-x)==2 && abs(targetY-y)==2)
        {
            if(board[(x + targetX) / 2][(y + targetY) / 2].name == "empty") return 1;
            else return 0;
        }
        else return 0;
	}

    if(board[x][y].name=="pawn")
    {
        int a;
        if(board[x][y].owner==1) a = 1;
        else a = -1;

        if((targetX == x) && (targetY == y + 2 * a)) return 1;
        else if((targetX == x + 1) && (targetY == y + a)) return 1;
        else if((targetX == x - 1) && (targetY == y + a)) return 1;
        else return 0;
    }

    if(board[x][y].name=="king")
    {
        if((abs(targetX - x) == 1) && (abs(targetY - y) == 1)) return 1;
        if((targetX == x) && (abs(targetY - y) == 2)) return 1;
        return 0;
    }

    if(board[x][y].name=="ghost")
    {
        if((abs(targetX - x) == 1) && (abs(targetY - y) == 3)) return 1;
        if((abs(targetX - x) == 2) && (abs(targetY - y) == 0)) return 1;
        else return 0;
    }

    //kawaleria
    if(board[x][y].name=="cav")
    {
        int d_x;
        int d_y;
        if(targetX > x) d_x = 1;
        else d_x = -1;
        if(targetY > y) d_y = 1;
        else d_y = -1;

        if(abs(targetX - x) != abs(targetY - y))
        {
            return 0;
        }

        int opponent_owner;
        if(board[x][y].owner == 1)
        {
            opponent_owner = 2;
        }
        else
        {
            opponent_owner = 1;
        }

        for(int i = 1; i < abs(targetX - x); i ++)
        {
            if(board[i * d_x + x][i * d_y + y].name == "notexist")
            {
                return 0;
            }
            if(board[i * d_x + x][i * d_y + y].name != "empty")
            {
                if((targetX == i * d_x + d_x + x) && (targetY == i * d_y + d_y + y))
                {
                    return 1;
                }
                if((board[i * d_x + x][i * d_y + y].owner == opponent_owner) &&
                   (board[(i + 1) * d_x + x][(i + 1) * d_y + y].name == "empty") &&
                   (board[(i + 2) * d_x + x][(i + 2) * d_y + y].owner == opponent_owner) &&
                   (targetX == (i + 3) * d_x + x) && (targetY == (i + 3) * d_y + y))
                {
                    return 1;
                }
                else return 0;
            }
        }
        return 1;
    }

    //zagadka
    if(board[x][y].name=="mystery")
    {
        int d_x;
        int d_y;
        int changes;

        if(targetX  == x)
        {
            d_x = 0;
            if(targetY > y) d_y = 2;
            else d_y = -2;

            changes = abs((targetY - y) / 2);        //
        }
        else
        {
            if(targetX > x) d_x = 1;
            else d_x = - 1;

            if(targetY > y) d_y = 1;
            else d_y = -1;

            changes = abs(targetY - y);
        }

        for(int i = 1; i < changes; i ++)
        {
            //kiedy jest figura
            if(board[i * d_x + x][i * d_y + y].name != "empty")
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

bool canAttack(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    if(wsk_to_board[x * 34 + y].name == "king")
    {
        return CanMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "ghost")
    {
        return CanMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "charge")
    {
        return CanMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "mystery")
    {
        return CanMove(wsk_to_board, x, y, targetX, targetY);
    }
    if(wsk_to_board[x * 34 + y].name == "cav")
    {
        return 0;
    }

    Pole board[17][34];

    for(int i = 0; i < 17; i ++)
    {
        for(int j = 0; j < 34; j ++)
        {
            board[i][j] = wsk_to_board[i * 34 + j];
        }
    }

    if(board[x][y].name=="tower")
    {
        if((x==targetX) && (abs(targetY-y)<=10) && (abs(targetY-y)>=4)) return 1;
        if((abs(targetX-x)==2) && (abs(y-targetY)==2)) return 1;
        if((abs(targetX-x)==3) && (abs(y-targetY)==3)) return 1;
        if((abs(targetX-x)==4) && (abs(y-targetY)==4)) return 1;
        if((abs(targetX-x)==5) && (abs(y-targetY)==5)) return 1;
        return 0;
    }
    if(board[x][y].name=="pawn")
    {
        int a;
        board[x][y].owner==1 ? a=1: a=-1;
        if((targetX==x) && (a*(targetY - y)==2)) return 1;
        if((abs(targetX - x) == 1) &&  (abs(targetY - y) == 1)) return 1;
        return 0;

    }
}

void Move(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    /*
    sf::Texture Background;
    if (!Background.loadFromFile("img/dupa.png"))
    {
        ms_error(392, "Figures/Move/something wrong with file dupa.png");
        return;
    }
    */

    if((wsk_to_board[x * 34 + y].name == "cav") || (wsk_to_board[x * 34 + y].name == "charge"))
    {
        Pole board[17][34];

        for(int i = 0; i < 17; i ++)
        {
            for(int j = 0; j < 34; j ++)
            {
                board[i][j] = wsk_to_board[i * 34 + j];
            }
        }

        int d_x;
        int d_y;

        if(board[x][y].name == "charge")
        {
            if(targetY != y)
            {
                if(targetY > y) d_y = 1;
                else d_y = -1;

                for(int i = 1; i < abs(targetY - y); i ++)
                {
                    wsk_to_board[x * 34 + (i * d_y) + y].name = "empty";
                    wsk_to_board[x * 34 + (i * d_y) + y].owner = 0;
                    //board[x][i * d_y + y].setTexture(Background);
                }
            }
        }
        else if(board[x][y].name == "cav")
        {
            int opponent_owner;
            if(board[x][y].owner == 1) opponent_owner = 2;
            else opponent_owner = 1;

            if(targetX > x) d_x = 1;
            else d_x = -1;

            if(targetY > y) d_y = 1;
            else d_y = -1;

            if(board[targetX - d_x][targetY - d_y].owner == opponent_owner)
            {
                wsk_to_board[(targetX - d_x) * 34 + targetY - d_y].name = "empty";
                wsk_to_board[(targetX - d_x) * 34 + targetY - d_y].owner = 0;
                //board[targetX - d_x][targetY - d_y].setTexture(Background);
                if(board[targetX - (2 * d_x)][targetY - (2 * d_y)].name == "empty")
                {
                    if(board[targetX - (3 * d_x)][targetY - (3 * d_y)].owner == opponent_owner)
                    {
                        wsk_to_board[(targetX - (3 * d_x)) * 34 + targetY - (3 * d_y)].name = "empty";
                        wsk_to_board[(targetX - (3 * d_x)) * 34 + targetY - (3 * d_y)].owner = 0;
                        //board[targetX - (3 * d_x)][targetY - (3 * d_y)].setTexture(Background);
                    }
                }
            }
        }
    }

    wsk_to_board[targetX * 34 + targetY].name = wsk_to_board[x * 34 + y].name;
    wsk_to_board[targetX * 34 + targetY].owner = wsk_to_board[x * 34 + y].owner;
    //wsk_to_board[targetX * 34 + targetY].setTexture(wsk_to_board[x * 34 + y].getTexture());
    //wsk_to_board[x * 34 + y].setTexture(Background);
    wsk_to_board[x * 34 + y].name = "empty";
    wsk_to_board[x * 34 + y].owner = 0;
}

void Attack(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    if(wsk_to_board[x * 34 + y].name == "ghost")
    {
        Move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "king")
    {
        Move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "charge")
    {
        Move(wsk_to_board, x, y, targetX, targetY);
        return;
    }
    if(wsk_to_board[x * 34 + y].name == "mystery")
    {
        Move(wsk_to_board, x, y, targetX, targetY);
        return;
    }

    wsk_to_board[targetX * 34 + targetY].name = "empty";
    wsk_to_board[targetX * 34 + targetY].owner = 0;
}

bool Action(Pole *wsk_to_board, int x, int y, int targetX, int targetY)
{
    int opponent_owner;
    if(wsk_to_board[x * 34 + y].owner == 1) opponent_owner = 2;
    else opponent_owner = 1;

    if(wsk_to_board[targetX * 34 + targetY].name == "empty")
    {
        if(CanMove(wsk_to_board, x, y, targetX, targetY))
        {
            Move(wsk_to_board, x, y, targetX, targetY);
            return 1;
        }
    }
    else if(wsk_to_board[targetX * 34 + targetY].owner == opponent_owner)
    {
        if(canAttack(wsk_to_board, x, y, targetX, targetY))
        {
            if(wsk_to_board[targetX * 34 + targetY].name=="king"){
                Attack(wsk_to_board, x, y, targetX, targetY);
                win=1;
            }
            Attack(wsk_to_board, x, y, targetX, targetY);
            return 1;
        }
    }

    ms_message("Niepoprawne dane!!!");
    return 0;
}


//===================[highLight]=================

/*void highLight(Pole *wsk_to_board, int xx, int yy,){
    for(int k = xx; k < 17; k++){
        for (int l = yy; l < 34; l++){
            if(canAttack(wsk_to_board), xx, yy, k, l){
                //pokoloruj pole wsk_to_board[(xx+k)*34 + yy] na czerwono;
            }
            if(canMove(wsk_to_board), xx, yy, k, l){
                //pokoloruj pole wsk_to_board[(xx+k)*34 + yy] na pomaranczowo;
            }     
        }
    }
}*/