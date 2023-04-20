#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>

#include <iostream>
class Enemy
{
    public:
        Enemy(float pos_x, float pos_y,int shipType);
        virtual ~Enemy();
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget& target);
        sf::Sprite enemySprite;
        float speedY;
        float speedX;
        int Type;

    protected:

    private:

        sf::Texture enemyTexture;

        int hp;//no se utiliza
        int hpMax;//no se utiliza
        int damage;//no se utiliza
        int points;//no se utiliza
        void initShape();
        void initVariables(int shipType);
        void initSprite();
        void initTexture(int shipType);
        float spawnTimer;//temporizador de despliegue de naves enemigas
        float spawnTimerMax;//maximo tiempo antes del despliegue

};

#endif // ENEMY_H
