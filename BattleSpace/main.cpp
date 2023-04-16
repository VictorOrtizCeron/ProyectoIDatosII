#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Game.h"
#include <iostream>
#include <time.h>
#include "MainMenu.h"
#include "libxml2/libxml/parser.h"

// Proyecto 1 Datos 2
// Fernando Fuchs 2020144908
// Victor Ortiz 2020426044

using namespace sf;



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
                        srand(time(static_cast<unsigned>(0)));
                        Game game(1);

                        //game functions
                        game.run();
                        }

                    if(x == 1){

                        srand(time(static_cast<unsigned>(0)));
                        Game game(2);

                        //game functions
                        game.run();
                        }

                    if(x == 2){
                        srand(time(static_cast<unsigned>(0)));
                        Game game(3);

                        //game functions
                        game.run();
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
    //StartMenu();


    //por ahora solo estamos abriendo el game window desde el main, la idea esa que se abra desde menu, esto es
    // solo para testear funcionalidad
    //StartMenu();

    return 0;
}
