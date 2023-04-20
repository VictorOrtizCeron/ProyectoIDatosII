#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


#define Max_main_menu 4
class MainMenu
{
    public:

        MainMenu(float width, float height);
        void draw(RenderWindow& window);
        void moveUp();
        void moveDown();

        int MainMenuPressed(){
            return MainMenuSelected;
        }
        ~MainMenu();

    private:
        int MainMenuSelected;
        Font font;//fuente
        Text mainMenu[Max_main_menu];//arreglo de opciones del menu

};

#endif // MAINMENU_H
