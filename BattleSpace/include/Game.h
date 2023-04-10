#ifndef GAME_H
#define GAME_H
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include<map>
#include "BulletLinkedList.h"
#include <iostream>
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
        BulletLinkedList* Collector;//lista de balas que no impactaron enemigos
        BulletLinkedList* Magazine;//Lista enlazada de balas
        BulletLinkedList* shotBullets; //Lista de balas disparadas
        float spawnTimer;
        float spawnTimerMax;
        std::vector<Enemy*>enemies;

        std::map <std::string, sf::Texture*>textures;
        std::vector<Bullet*> bullets;
        void initWindow();
        void initTextures();
        void initPlayer();
        void initEnemies();
        void initCollector();
        void initMagazine(int i);
        void initshotBullets();

};

#endif // GAME_H
