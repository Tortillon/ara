    #include <math.h>
    //#include <windows.h>

    #define board_size_y 34

    Pole background_fields[17][34];
    Pole *front_fields;


     sf::Color gColor=sf::Color(215,255,215,165);
     sf::Color rColor=sf::Color(255,180,180,195);
     sf::Color bColor=sf::Color(175,210,255,210);
     sf::Color yColor=sf::Color(255,220,175,200);


    //HWND hWnd = GetConsoleWindow();

    //----------[super zmienne]---------------
        std::string empty = "empty";

    //----------------------------------------

    int figure_x = 0;
    int figure_y = 0;
    int target_x = 0;
    int target_y = 0;

    std::string actual_mode = "play"; //aktualny tryb dzialania myszki: "play", "edit"

    sf::Vector2i mouse_position;
    bool mouse_pressed = 0;
    int mouseX;
    int mouseY;
    int mouseDX;
    int mouseDY;
    int mouseFieldX;
    int mouseFieldY;
    bool mousePointing;

    float stalaX=-60;
    float stalaY=50;



    std::string actual_name = "pawn";
    int actual_owner = 0;

    sf::SoundBuffer buffer;
    sf::Sound sound;


    bool isMenu=0;
    bool isSaving=0;
    int opponentOwner;

    bool clickInMenu=1;
    bool clickInSaving=1;

    //======do AI========\\

    int aiFX;
    int aiFY;
    int aiTX;
    int aiTY;

    //==================\\

    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width-1, sf::VideoMode::getDesktopMode().height-1), "A.R.A.", sf::Style::None);



/*
void consoleHiding(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            ShowWindow( hWnd, SW_HIDE );
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            ShowWindow( hWnd, SW_SHOW );
        }
}
*/

