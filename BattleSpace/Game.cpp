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
    this->textures["Bullet"]->loadFromFile("misil2.png");

}
void Game::initPlayer()
{
    this->player = new Player();

}

void Game::initGatheringCollector()
{
    this->gatheringCollector = new BulletLinkedList();
}
void Game:: initShootingCollector(){

    this-> shootingCollector = new BulletLinkedList();
}
void Game::initMagazine(int i){

    if(this->Level==1){
        this -> Magazine = new BulletLinkedList();
        for(int j =0 ; j<i;j++){

            Magazine -> addFirst(new Bullet());

        }
    }
    else{
        std::cout<<"entra al else de init Magazine"<<std::endl;
        for(int j =0 ; j<i;j++){

            Magazine -> addFirst(new Bullet());

        }

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

    this->text[2].setFont(this->font);
    this->text[2].setString("Wave: ");
    this->text[2].setCharacterSize(20);
    this->text[2].setFillColor(sf::Color::White);
    this->text[2].setPosition(700, 650);

    this->text[3].setFont(this->font);
    this->text[3].setString("Level: ");
    this->text[3].setCharacterSize(20);
    this->text[3].setFillColor(sf::Color::White);
    this->text[3].setPosition(900, 650);

}
void Game:: initFont(){

    if (!font.loadFromFile("RobotoMono-VariableFont_wght.ttf")) {
        std::cout<<"fallo la carga de font"<<std::endl;
    }

}



void Game:: initEnemyWaves(){
    this->waveCounter = 0;

    for (int i = 0; i<5; i++){


        enemyLinkedList* Wave = new enemyLinkedList();

        for(int j =0; j<this->WaveEnemies ; j++){

            if(j%2 ==0){
                Enemy* enemyPTR = new Enemy(1400,rand()%670,1);
                enemyPTR->speedX = this->enemySpeedX;
                Wave->addFirst(enemyPTR);
            }
            else{

                Enemy* enemyPTR = new Enemy(1400,rand()%670,0);
                enemyPTR->speedX = this->enemySpeedX;
                Wave->addFirst(enemyPTR);
            }

        }
        this->EnemyWaves[i]= Wave;

    }

}


void Game::initEnemyRenderList(){
    this-> EnemyRenderList = new enemyLinkedList();

}
void Game::initTimers(){

    this->spawnTimerMax = 100.f;
    this->spawnTimer = this->spawnTimerMax;
    this->nextWaveTimer = 0.f;
    this->nextWaveTimerMax = 200.f;
    this->waitNextWave = true;

}

Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initPlayer();
    this->initTimers();
    this->initGatheringCollector();
    this->initShootingCollector();
    this->initshotBullets();
    this->initMagazine(200);
    this->initFont();
    this->initText();
    this->initTimers();

    this->initEnemyRenderList();
    this->initEnemyWaves();
    this->initTimers();
}
Game::Game(int difficulty)
{
    this->initWindow();
    this->initTextures();
    this->initPlayer();
    this->initTimers();
    this->initGatheringCollector();
    this->initShootingCollector();
    this->initshotBullets();

    if(difficulty==1){
        this->bullets=200;
        this->WaveEnemies = 7;
        this->enemySpeedX = -2.f;
        }
    if(difficulty==2){
        this->bullets=180;
        this->WaveEnemies = 10;
        this->enemySpeedX = -4.f;
        }
    if(difficulty==3){
        this->bullets=160;
        this->WaveEnemies = 13;
        this->enemySpeedX = -6.f;
        }
    this->Level=1;
    this->initMagazine(bullets);
    this->initFont();
    this->initText();
    this->initTimers();

    this->initEnemyRenderList();
    this->initEnemyWaves();
    this->initTimers();
    this->serial_port= fopen("/dev/ttyUSB0","r+");
    this->CurrentPotVal= 0;
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


    //corre lento pero corre

    char buffer[256];

    char analogBuffer[256];

    fscanf(serial_port, "%s",&buffer);
    fscanf(serial_port, "%s", &analogBuffer);
    int len = strlen(analogBuffer);
    memmove(analogBuffer,analogBuffer+2,len-1);
    analogBuffer[len-2]= '\0';

    //printf("%c %c %s \n", buffer[0],buffer[1],analogBuffer);

    if(buffer[0]== '1'){

        this->player->move(0.f,-3.f);
    }
    if(buffer[1]== '1'){

        this->player->move(0.f,3.f);
    }



    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)&& this->player->getBounds().top>0)
        this->player->move(0.f,-3.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)&& this->player->getBounds().top+100<720)
        this->player->move(0.f,3.f);


    //Control de velocidad de disparo
    //velocidad de disparo por default 10.f

    int potVal = std::atoi(analogBuffer);

    if(potVal > this->CurrentPotVal){
        this->player->SlowAttackCooldownMax(1.f);
        this->CurrentPotVal = potVal;
    }
    if(potVal < this->CurrentPotVal){
        this->player->SlowAttackCooldownMax(-1.f);
        this->CurrentPotVal = potVal;
    }

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

            shotBullets->addFirst(bulletPTR);

        }
        else{
            if (Magazine->size==0){

                //std::cout<<"no ammo"<<std::endl;

            }
            else{
                Bullet* bulletPTR = Magazine->head->bullet;
                this->Magazine->removeFirst();
                bulletPTR->resetParams(this->textures["Bullet"],this->player->getPos().x+20 + this->player->getBounds().width/2.f,
                this->player->getPos().y+40,
                1.f,0.f,5.f);

                shotBullets->addFirst(bulletPTR);

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
                //std::cout<<gatheringCollector->size<<std::endl;
            }

            current = current->nextBullet;
        }
    }
}

void Game::updateEnemies()
{


    this->nextWaveTimer += 0.5f;

    if(nextWaveTimer >= nextWaveTimerMax){

        waitNextWave = false;

    }
    else{


        waitNextWave = true;
    }


    enemyNode* current = this->EnemyRenderList->head;

    bulletNode* currentBullet = this->shotBullets->head;

    this->spawnTimer += 0.5f;

    if(waitNextWave == false){
        if(this->spawnTimer >=this->spawnTimerMax)
        {
            if(this->EnemyWaves[this->waveCounter]->head == nullptr){


                this->waveCounter++;
                //std::cout<<this->waveCounter<<std::endl;
                this->nextWaveTimer = 0.f;


            }

            else{

                EnemyRenderList->addFirst(EnemyWaves[this->waveCounter]->removeFirst());

                this->spawnTimer = 0.f;
            }
        }

    }
    while(current != nullptr)
        {
            current->enemy->update();
            if(current->enemy->getBounds().top<0 ||current->enemy->getBounds().top+100>720){

                current->enemy->speedY = current->enemy->speedY *-1.f;
            }
            if(current->enemy->getBounds().left+100<0){

                Enemy* enemyPTR = this->EnemyRenderList->removeEnemy(current->enemy);
                delete(enemyPTR);
            }

            while(currentBullet!=nullptr){

                //Deteccion de colisiones, requiere mejoras con el png
                if(current->enemy->getBounds().intersects(currentBullet->bullet->getBounds())){

                    Bullet *bulletPTR = shotBullets->removeBullet(currentBullet->bullet);

                    Enemy * enemyPTR = EnemyRenderList->removeEnemy(current->enemy);

                    delete(bulletPTR);


                    delete(enemyPTR);
                }
                currentBullet = currentBullet->nextBullet;

            }

            current = current->nextEnemy;
        }

}
void Game::updateLevel(){

    std::cout<<this->waveCounter<<std::endl;
    if(waveCounter>4){

        this->waveCounter = 0;
        this->Level = this->Level+1;

        for (int i = 0 ; i<5 ;i++){


            delete(this->EnemyWaves[i]);
        }
        this->initEnemyWaves();
        this->initMagazine(this->bullets);
        //meter balas de gatheringCollector a shootingCollector
    }
}
void Game::updateText(){

    std::string shootingSpeed = "Shooting Speed: " + std::to_string(this->player->getCooldown());

    this->text[0].setString(shootingSpeed);

    std::string Ammo = "Ammunition: " + std::to_string(this->Magazine->size);

    this->text[1].setString(Ammo);


    int x = this->waveCounter;
    std::string wave = "Wave: "+ std::to_string(x+1);

    this->text[2].setString(wave);

    this->text[3].setString("Level:" +std::to_string(this->Level));
}

void Game::renderText(){

    for (int i = 0; i< 5; i++){
        this->window->draw(text[i]);
    }

}
void Game::update()
{
    this->updatePollEvents();
    this->updateInput();
    this->player->update();

    this->updateLevel();
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
