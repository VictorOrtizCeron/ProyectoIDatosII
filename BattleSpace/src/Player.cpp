#include "Player.h"
//inicializacion de variables del jugador
void Player::initVariables()
{
    this->movementSpeed = 1.f;
    this->attackCooldownMax=15.f;
    this->attackCooldown=this->attackCooldownMax;
}
//inicializacion de textura
void Player::initTexture()
{
    //funcion que llama la imagen del mainship
    if (!this->textura.loadFromFile("MainShip.png"))
    {
        std::cout<<"Error no se cargo la imagen"<<"\n";

    }
}
//inicializacion del sprite
void Player::initSprite()
{
    this->imagen.setTexture(this->textura);
}
//constructor de jugador
Player::Player()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
}
//destructor de jugador
Player::~Player()
{

}
//funcion que retorna posicion del jugador
const sf::Vector2f&Player::getPos()const
{
    return this->imagen.getPosition();
}
//funcion que retorna los bordes globales de la nave principal
const sf::FloatRect Player::getBounds() const
{
    return this->imagen.getGlobalBounds();
}
//funcion que mueve jugador
void Player::move(const float dirX, const float dirY)
{

    this->imagen.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}
//funcion que cambia velocidad de disparo
void Player::SlowAttackCooldownMax(float increment){

    if(attackCooldownMax == 5 && increment>0){
        this->attackCooldownMax = this->attackCooldownMax + increment;
    }
    if(attackCooldownMax == 30 && increment<0){
        this->attackCooldownMax = this->attackCooldownMax + increment;
    }
    if(attackCooldownMax<30 && attackCooldownMax> 5){

        this->attackCooldownMax = this->attackCooldownMax + increment;
    }
    else{
        return;
    }




}
// getter de velocidad de disparo
float Player::getCooldown(){
    return this->attackCooldownMax;
}
//funcion de validacion de si jugador puede o no disparar
const bool Player::canAttack()
{
    if(this->attackCooldown>=this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}
//funcion de tiempo auxiliar de update()
void Player::updateAttack()
{
    if(this->attackCooldown<this->attackCooldownMax)
        this->attackCooldown+=0.5f;
}
//funcion actualizadora
void Player::update()
{
    this->updateAttack();
}
//funcion renderizadora
void Player::render(sf::RenderTarget& target)
{
    target.draw(this->imagen);
}
