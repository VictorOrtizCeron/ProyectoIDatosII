#include "Game.h"

//private functions
void Game::initWindow()
{
    this-> window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Ventana de Juego");
    this-> window ->setFramerateLimit(144);
    this-> window ->setVerticalSyncEnabled(false);
}
void Game::initTextures()
{
    this->textures["Bullet"] = new sf::Texture();
    this->textures["Bullet"]->loadFromFile("misil.png");
}
void Game::initPlayer()
{
    this->player = new Player();
}

void Game::initCollector()
{
    this->Collector = new BulletLinkedList();
}
void Game::initMagazine(int i){

    this -> Magazine = new BulletLinkedList();
    for(int j =0 ; j<=i;j++){

        Magazine -> addFirst(new Bullet());

    }

}

void Game::initshotBullets(){

        this-> shotBullets = new BulletLinkedList();
}
void Game::initEnemies()
{
    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
    this-> initWindow();
    this->initTextures();
    this-> initPlayer();
    this->initEnemies();
    this-> initCollector();
    this-> initshotBullets();
    this-> initMagazine(0);
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    for(auto&i : this->textures)
    {
        delete i.second;
    }

    //Borra las balas del juego
    for (auto *i : this->bullets)
    {
        delete i;
    }
    //Borra los enemigos del juego
    for (auto *i : this->enemies)
    {
        delete i;
    }
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
void Game::updatePollEvents()
{
    //permite cerrar la ventana del juego usando la tecla escape
    sf::Event evento;
    while(this->window->pollEvent(evento))
    {
        if(evento.Event::type==sf::Event::Closed)
            this->window->close();
        if(evento.Event::KeyPressed&&evento.Event::key.code==sf::Keyboard::Escape)
            this->window->close();
    }
}

void Game::updateInput()
{
     //movimiento del main ship

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f,-3.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f,3.f);

    //thread
    //en este codigo hace que se disparen las balas hay que pasarlo a que sea automatico
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&this->player->canAttack()){

        Bullet *newBullet = new Bullet(this->textures["Bullet"],this->player->getPos().x + this->player->getBounds().width/2.f,
        this->player->getPos().y,
        1.f,0.f,5.f);

        std::cout<<newBullet<<std::endl;
        this->shotBullets->addFirst(newBullet);
        shotBullets->printList(this->shotBullets->head);
        std::cout<<shotBullets->size<<std::endl;

        }
    }

void Game::updateBullets(){

    bulletNode *current = this->shotBullets->head;
        if(current != nullptr){
        while (current != nullptr) {

            // Move the projectile sprite

            current->bullet->update();

            // Check if projectile is offscreen and remove it if it is
            if (current->bullet->getBounds().left > 1300) {
                //meter en lista collector
            }

            current = current->nextBullet;
            }
        }

}

void Game::updateEnemies()
{
    this->spawnTimer += 0.5f;
    if(this->spawnTimer >=this->spawnTimerMax)
    {
        //this->enemies.push_back(new Enemy(rand()%this->window->getSize().x-20.f,-100.f);
        this->spawnTimer = 0.f;
    }
    for (int i = 0; i<this->enemies.size(); ++i)
    {
        //this->enemies{i}->update();
       // if(this->enemies[i].get)
    }

}

void Game::update()
{
    this->updatePollEvents();
    this->updateInput();
    this->player->update();
    this->updateBullets();

    //this->updateEnemies();
}
void Game::render()
{
    this->window->clear();
    this->player->render(*this->window);


    this->shotBullets->drawAll(*this->window);

    this->window->display();
}
