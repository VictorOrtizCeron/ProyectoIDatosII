#include <SFML/Graphics.hpp>
#include <stdio.h>

#include <iostream>
#include "MainMenu.h"

// Proyecto 1 Datos 2
// Fernando Fuchs 2020144908
// Victor Ortiz 2020426044

using namespace sf;
void mainWindow(){

sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");


        sf::Texture mainShiptexture;
        if (!mainShiptexture.loadFromFile("MainShip.png"))
        {

            std::cout<<"Failed to load MainSHip texture" ;
        }


        sf::Sprite mainShip;
        mainShip.setTexture(mainShiptexture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(mainShip);
            window.display();
        }

}

void StartMenu(){
    RenderWindow MENU(VideoMode(960,720) ,"Main Menu", Style::Default);
    MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);


    RectangleShape background;
    background.setSize(Vector2f(960,720));
    Texture menuTexture;
    menuTexture.loadFromFile("MainMenuBackground.jpg");
    background.setTexture(&menuTexture);

    while(MENU.isOpen()){

        Event event;
        while(MENU.pollEvent(event)){
            if(event.type == Event::Closed){

                    MENU.close();
                }
            if(event.type == Event::KeyReleased ){

                if(event.key.code ==  Keyboard::Up){
                    mainMenu.moveUp();
                    break;
                    }
                if(event.key.code ==  Keyboard::Down){
                    mainMenu.moveDown();
                    break;
                    }
                if(event.key.code == Keyboard::Return){
                    mainWindow();
                    int x = mainMenu.MainMenuPressed();
                    std::cout<< x << std::endl;
                    //funcionalidades de los botones para compenzar partidas
                    }
                }

        }
    MENU.clear();
    MENU.draw(background);
    mainMenu.draw(MENU);
    MENU.display();

    }
}

int main()
{
    StartMenu();

    return 0;
}
