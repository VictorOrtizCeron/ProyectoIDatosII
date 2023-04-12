#include "Enemy.h"


void Enemy::initVariables()
{
        this->type = 0;
        this->hpMax = 10;
        this->hp = 0;
        this->damage = 1;
        this->points = 5;

}
//codigo para cambiar los "shapes" por la imagen de la nave rival
void Enemy::initTexture(){

    if (!this->enemyTexture.loadFromFile("GreenShip.png")){
            std::cout<<"Error no se cargo la imagen"<<std::endl;
        }
}

void Enemy::initSprite()
{
    this->enemySprite.setTexture(this->enemyTexture);
}
Enemy::Enemy(float pos_x, float pos_y)
{

    this->initVariables();
    this->initTexture();
    this->initSprite();
    this->enemySprite.setPosition(pos_x,pos_y);
}

Enemy::~Enemy()
{
    //dtor
}


void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget& target)
{
    target.draw(this->enemySprite);
}
