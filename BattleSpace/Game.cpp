#include "Game.h"

//private functions
void Game::initWindow()
{
    this-> window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Ventana de Juego");
;
}
//con/des
Game::Game()
{
    this-> initWindow();
}

Game::~Game()
{
    delete this->window;
}

//functions

void Game::run()
{
    while(this->window->isOpen())
    {
        this->update();
        this->render();

    }

}
void Game::update()
{

}
void Game::render()
{
    this->window->clear();
    this->window->display();
}
