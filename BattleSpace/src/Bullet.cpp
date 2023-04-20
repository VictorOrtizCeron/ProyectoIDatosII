#include "Bullet.h"

Bullet::Bullet()
{

}
//constructor de bala con parametros
Bullet::Bullet(sf::Texture* texture,float pos_x,float pos_y, float dir_x, float dir_y, float movement_speed)
{

    this->shape.setTexture(*texture);
    this->shape.setPosition(pos_x,pos_y);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;
}
//desctructor de bala
Bullet::~Bullet()
{

}
//funcion que reinicia todos los parametros de la bala
void Bullet::resetParams(sf::Texture* texture,float pos_x,float pos_y, float dir_x, float dir_y, float movement_speed){

    this->shape.setTexture(*texture);
    this->shape.setPosition(pos_x,pos_y);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;


}
//funcion que retorna los bordes de la bala
const sf::FloatRect Bullet::getBounds() const
{
    return this->shape.getGlobalBounds();
}
// funcion que actualiza la bala
void Bullet::update()
{

    this->shape.move(this->movementSpeed*this->direction);
}
//funcion de renderizacion de bala
void Bullet::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
