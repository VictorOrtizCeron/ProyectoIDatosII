#ifndef GAME_H
#define GAME_H
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include<map>


class Game
{
    public:
        Game();
        virtual ~Game();
        void run();
        void updatePollEvents();
        void updateInput();
        void updateBullets();
        void updateEnemies();
        void update();
        void render();

    protected:

    private:
        sf::RenderWindow* window;
        Player* player;
        float spawnTimer;
        float spawnTimerMax;
        std::vector<Enemy*>enemies;

        std::map <std::string, sf::Texture*>textures;
        std::vector<Bullet*> bullets;
        void initWindow();
        void initTextures();
        void initPlayer();
        void initEnemies();
};

#endif // GAME_H
