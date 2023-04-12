#ifndef GAME_H
#define GAME_H
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include<map>
#include "BulletLinkedList.h"
#include <iostream>
#include <string>

#define Max_inGame 4

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
        void updateText();
        void renderText();

    protected:

    private:
        sf::RenderWindow* window;
        sf::Text text[Max_inGame];
        sf::Font font;
        Enemy* enemy;
        Player* player;
        BulletLinkedList* gatheringCollector;//lista de balas que no impactaron enemigos en la ronda actual
        BulletLinkedList* shootingCollector;//lista de balas recogidas en ronda anterior que se van a disparar
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
        void initGatheringCollector();
        void initShootingCollector();
        void initMagazine(int i);
        void initshotBullets();
        void initText();
        void initFont();
};

#endif // GAME_H
