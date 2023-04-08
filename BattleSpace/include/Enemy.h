#ifndef ENEMY_H
#define ENEMY_H
#include<SFML/Graphics.hpp>


class Enemy
{
    public:
        Enemy(float pos_x, float pos_y);
        virtual ~Enemy();
        const sf::FloatRect getBounds() const;
        void update();
        void render(sf::RenderTarget* target);

    protected:

    private:
        //sf::Sprite senemy;
        //sf::Texture tenemy;
        sf::CircleShape shape;
        int type;
        int hp;
        int hpMax;
        int damage;
        int points;
        void initShape();
        void initVariables();
        //void initSprite();
        //void initTexture();
};

#endif // ENEMY_H
