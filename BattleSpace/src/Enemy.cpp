#include "Enemy.h"


void Enemy::initShape()
{
    this->shape.setRadius(rand()%20+20);
    this->shape.setPointCount(rand()%100+3);
    this->shape.setFillColor(sf::Color(rand()%255+1,rand()%255+1,rand()%255+1,255));
}

void Enemy::initVariables()
{
        this->type = 0;
        this->hpMax = 10;
        this->hp = 0;
        this->damage = 1;
        this->points = 5;
}

//codigo para cambiar los "shapes" por la imagen de la nave rival
/*void Enemy::initTexture()
{
    this->tenemy.loadFromFile("RedShip.png");
}
void Enemy::initSprite()
{
    this->senemy.setTexture(this->tenemy);
}*/
Enemy::Enemy(float pos_x, float pos_y)
{
    this->initShape();
    this->initVariables();
    this->shape.setPosition(pos_x,pos_y);
}

Enemy::~Enemy()
{
    //dtor
}



void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
