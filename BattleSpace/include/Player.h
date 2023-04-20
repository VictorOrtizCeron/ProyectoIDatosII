#ifndef PLAYER_H
#define PLAYER_H
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Player
{
    public:
        Player();
        virtual ~Player();
        const sf::Vector2f& getPos() const;
        const  sf::FloatRect getBounds() const;
        //funciones a utilizar
        void move(const float dirX, const float dirY);
        const bool canAttack();
        void updateAttack();
        void update();
        void render(sf::RenderTarget& target);
        void SlowAttackCooldownMax(float increment);
        float getCooldown();
    protected:

    private:
        sf::Sprite imagen;//figura de la nave
        //la variable textura se refiere al main ship del juego
        sf::Texture textura;//imagen png de la nave
        float movementSpeed;
        float attackCooldown;//temporizador de ataque
        float attackCooldownMax;//maximo temporizador para atacar
        void initVariables();
        void initTexture();
        void initSprite();
};

#endif // PLAYER_H
