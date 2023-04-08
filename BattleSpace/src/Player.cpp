#include "Player.h"

void Player::initVariables()
{
    this->movementSpeed = 1.f;
    this->attackCooldownMax=10.f;
    this->attackCooldown=this->attackCooldownMax;
}
void Player::initTexture()
{
//funcion que llama la imagen del mainship
    if (!this->textura.loadFromFile("MainShip.png"))
    {
        std::cout<<"Error no se cargo la imagen"<<"\n";

    }
}
void Player::initSprite()
{
    this->imagen.setTexture(this->textura);
}


Player::Player()
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f&Player::getPos()const
{
    return this->imagen.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
    return this->imagen.getGlobalBounds();
}

void Player::move(const float dirX, const float dirY)
{
    this->imagen.move(this->movementSpeed*dirX,this->movementSpeed*dirY);
}

const bool Player::canAttack()
{
    if(this->attackCooldown>=this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::updateAttack()
{
    if(this->attackCooldown<this->attackCooldownMax)
        this->attackCooldown+=0.5f;
}
void Player::update()
{
    this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->imagen);
}