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
    this->textures["GreenShip"] = new sf::Texture();
    this->textures["GreenShip"]->loadFromFile("GreenShip.png");
}
void Game::initPlayer()
{
    this->player = new Player();
    this->enemy = new Enemy(20.f,20.f);
}

void Game::initGatheringCollector()
{
    this->gatheringCollector = new BulletLinkedList();
}
void Game:: initShootingCollector(){

    this-> shootingCollector = new BulletLinkedList();
}
void Game::initMagazine(int i){

    this -> Magazine = new BulletLinkedList();
    for(int j =0 ; j<i;j++){

        Magazine -> addFirst(new Bullet());

    }

}

void Game::initshotBullets(){

        this-> shotBullets = new BulletLinkedList();
}

void Game:: initText(){

    this->text[0].setFont(this->font);
    this->text[0].setString("Shooting Speed");
    this->text[0].setCharacterSize(20);
    this->text[0].setFillColor(sf::Color::White);
    this->text[0].setPosition(100, 650);

    this->text[1].setFont(this->font);
    this->text[1].setString("Ammunition:");
    this->text[1].setCharacterSize(20);
    this->text[1].setFillColor(sf::Color::White);
    this->text[1].setPosition(500, 650);

}
void Game:: initFont(){

    if (!font.loadFromFile("RobotoMono-VariableFont_wght.ttf")) {
        std::cout<<"fallo la carga de font"<<std::endl;
    }

}

void Game:: initEnemyMagazine(){

    this->EnemyMagazine = new enemyLinkedList();

    for(int i =0; i<7 ; i++){

        this->EnemyMagazine->addFirst(new Enemy(1100,rand()%690));

    }
}
void Game::initEnemyRenderList(){
    this-> EnemyRenderList = new enemyLinkedList;

}
void Game::initEnemies(){

    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initPlayer();
    this->initEnemies();
    this->initGatheringCollector();
    this->initShootingCollector();
    this->initshotBullets();
    this->initMagazine(150);
    this->initFont();
    this->initText();
    this->initEnemies();
    this->initEnemyMagazine();
    this->initEnemyRenderList();
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

    //Borra los enemigos del juego

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
    //Control de velocidad de disparo
    //velocidad de disparo por default 10.f
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        this->player->SlowAttackCooldownMax(0.5f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        this->player->SlowAttackCooldownMax(-0.5f);


    //thread
    //en este codigo hace que se disparen las balas hay que pasarlo a que sea automatico
    if(this->player->canAttack()){


        //Condicional que evalúa si se va a utilizar una bala de bullet collector
        if(shootingCollector-> size > 0){

            Bullet* bulletPTR = shootingCollector->head->bullet;
            this->shootingCollector->removeFirst();

            //reinicia los parámetros de las balas reutilizadas.
            bulletPTR->resetParams(this->textures["Bullet"],this->player->getPos().x + this->player->getBounds().width/2.f,
            this->player->getPos().y,
            1.f,0.f,5.f);
            std::cout<< bulletPTR<<std::endl;
            shotBullets->addFirst(bulletPTR);

        }
        else{
            if (Magazine->size==0){

                std::cout<<"no ammo"<<std::endl;

            }
            else{
                Bullet* bulletPTR = Magazine->head->bullet;
                this->Magazine->removeFirst();
                bulletPTR->resetParams(this->textures["Bullet"],this->player->getPos().x + this->player->getBounds().width/2.f,
                this->player->getPos().y,
                1.f,0.f,5.f);

                shotBullets->addFirst(bulletPTR);
                std::cout<<Magazine->size<<std::endl;

            }
        }



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

                Bullet* bulletPTR = shotBullets->removeBullet(current->bullet);
                gatheringCollector->addFirst(bulletPTR);
            }

            current = current->nextBullet;
        }
    }
}

void Game::updateEnemies()
{
    enemyNode* current = this->EnemyRenderList->head;
    this->spawnTimer += 0.5f;
    if(this->spawnTimer >=this->spawnTimerMax)
    {

        EnemyRenderList->addFirst(EnemyMagazine->removeFirst());

        this->spawnTimer = 0.f;
    }
    while(current != nullptr)
    {
        current->enemy->update();
        current = current->nextEnemy;
    }

}
void Game::updateText(){

    std::string shootingSpeed = "Shooting Speed: " + std::to_string(this->player->getCooldown());

    this->text[0].setString(shootingSpeed);

    std::string Ammo = "Ammunition: " + std::to_string(this->Magazine->size);

    this->text[1].setString(Ammo);

}

void Game::renderText(){

    for (int i = 0; i< 4; i++){
        this->window->draw(text[i]);
    }

}
void Game::update()
{
    this->updatePollEvents();
    this->updateInput();
    this->player->update();
    this->updateBullets();
    this->updateText();
    this->updateEnemies();
}
void Game::render()
{
    this->window->clear();
    this->player->render(*this->window);

    this->shotBullets->drawAll(*this->window);
    this->EnemyRenderList->drawAllEnemies(*this->window);
    this->renderText();
    this->window->display();

}
