#include "MainMenu.h"
#include <iostream>

//Definiciones de las funciones de la clase Main Menu
MainMenu::MainMenu(float width, float height)
{
    if(!font.loadFromFile("8-BIT WONDER.TTF")){
        std::cout<<"Failed to load font";
    }
    //Play button
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(200,200);
    //Settings
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Settings");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(200,300);
    //about
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(200,400);

    //Exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(200,500);

    MainMenuSelected = -1;
}

MainMenu::~MainMenu()
{
    //dtor
}
//Draw MainMenu

void MainMenu:: draw(RenderWindow& window){

    for (int i = 0; i< Max_main_menu; i++){
        window.draw(mainMenu[i]);
    }

}

//MoveUp

void MainMenu::moveUp(){

    if(MainMenuSelected-1 >=0){

    mainMenu[MainMenuSelected].setFillColor(Color::White);

    MainMenuSelected--;
    if(MainMenuSelected == -1){

        MainMenuSelected=2;
        }

    mainMenu[MainMenuSelected].setFillColor(Color::Red);
    }
}


//MoveDown

void MainMenu::moveDown(){

    if(MainMenuSelected + 1 <= Max_main_menu){

        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if(MainMenuSelected ==4){
            MainMenuSelected=0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Red);
    }

}





