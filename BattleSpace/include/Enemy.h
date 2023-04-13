#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>

#include <iostream>
class Enemy
{
    public:
        Enemy(float pos_x, float pos_y);
        virtual ~Enemy();
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget& target);
        sf::Sprite enemySprite;
        float speedY;
        float speedX;

    protected:

    private:

        sf::Texture enemyTexture;
        int type;
        int hp;
        int hpMax;
        int damage;
        int points;
        void initShape();
        void initVariables();
        void initSprite();
        void initTexture();
        float spawnTimer;
        float spawnTimerMax;

};

#endif // ENEMY_H
