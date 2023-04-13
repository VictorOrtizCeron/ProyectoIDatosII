#include "Enemy.h"


void Enemy::initVariables(int shipType)
{
    if(shipType==0)
        {
        this->type = 0;
        this->hpMax = 10;
        this->hp = 0;
        this->damage = 1;
        this->points = 5;
        this->speedX = -2.f;
        this->speedY = -2.f;
        }
    else{
        this->type = 0;
        this->hpMax = 10;
        this->hp = 0;
        this->damage = 1;
        this->points = 5;
        this->speedX = -2.f;
        this->speedY = 0.f;
    }
}
//codigo para cambiar los "shapes" por la imagen de la nave rival
void Enemy::initTexture(int shipType){

    if(shipType == 0){
        if (!this->enemyTexture.loadFromFile("GreenShip.png")){
                std::cout<<"Error no se cargo la imagen"<<std::endl;
            }
        }
    else{
        if (!this->enemyTexture.loadFromFile("RedShip.png")){
                std::cout<<"Error no se cargo la imagen"<<std::endl;
            }

    }
}

void Enemy::initSprite()
{
    this->enemySprite.setTexture(this->enemyTexture);
}
Enemy::Enemy(float pos_x, float pos_y, int shipType)
{
    this->Type = shipType;
    this->initVariables(shipType);
    this->initTexture(shipType);
    this->initSprite();
    this->enemySprite.setPosition(pos_x,pos_y);
}

Enemy::~Enemy()
{
    //dtor
}

const sf::FloatRect Enemy::getBounds() const{

    return this->enemySprite.getGlobalBounds();
}

void Enemy::update()
{
    this->enemySprite.move(speedX,speedY);
}

void Enemy::render(sf::RenderTarget& target)
{
    target.draw(this->enemySprite);
}
