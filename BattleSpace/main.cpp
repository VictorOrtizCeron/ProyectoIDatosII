#include <SFML/Graphics.hpp>
#include <stdio.h>

#include <iostream>
#include "MainMenu.h"

// Proyecto 1 Datos 2
// Fernando Fuchs 2020144908
// Victor Ortiz 2020426044

using namespace sf;

void GameWindow(){

sf::RenderWindow window(sf::VideoMode(1280, 720), "Ventana de Juego");


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
    RenderWindow MENU(VideoMode(960,720) ,"Main Menu", Style::Close);
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

                if(event.key.code ==  Keyboard::W){
                    mainMenu.moveUp();
                    break;
                    }
                if(event.key.code ==  Keyboard::S){
                    mainMenu.moveDown();
                    break;
                    }
                if(event.key.code == Keyboard::Return){


                    int x = mainMenu.MainMenuPressed();//esto retorna el numero la opcion

                    //aqui van las funcionalidades de los botones para compenzar partidas
                    if(x == 0){
                        GameWindow();
                        }

                    if(x == 1){
                        std::cout<<"opciones"<< std::endl;
                        }

                    if(x == 2){
                        std::cout<<"about"<< std::endl;
                        }

                    if(x == 3){
                        MENU.close();
                        }
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
