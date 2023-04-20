#ifndef GAME_H
#define GAME_H
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include<map>
#include "BulletLinkedList.h"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include "enemyLinkedList.h"
#define Max_inGame 6
#include "libxml/parser.h"
#include "libxml/tree.h"

class Game
{
    public:
        Game();
        Game(int difficulty);
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
        void updateLevel();

    protected:

    private:
        sf::RenderWindow* window;
        sf::Text text[Max_inGame];
        sf::Font font;
        int waveCounter;//contador de oleada
        Enemy* enemy;
        int Level;
        int WaveEnemies;
        int bullets;
        int CurrentPotVal;
        float enemySpeedX;
        Player* player;
        BulletLinkedList* gatheringCollector;//lista de balas que no impactaron enemigos en la ronda actual
        BulletLinkedList* shootingCollector;//lista de balas recogidas en ronda anterior que se van a disparar
        BulletLinkedList* Magazine;//Lista enlazada de balas
        BulletLinkedList* shotBullets; //Lista de balas disparadas
        float spawnTimer;
        float spawnTimerMax;
        float nextWaveTimer;
        float nextWaveTimerMax;
        bool waitNextWave;
        enemyLinkedList* EnemyRenderList;

        std::string powerup;
        enemyLinkedList* EnemyWaves[5];//arreglo de listas enlazadas para enemigos
        std::map <std::string, sf::Texture*>textures;
        void print_element_names(xmlNode * a_node);
        void initWindow();
        void initTextures();
        void initPlayer();
        void initTimers();
        void initGatheringCollector();
        void initShootingCollector();
        void initMagazine(int i);
        void initshotBullets();
        void initText();
        void initFont();
        void initEnemyMagazine();
        void initEnemyRenderList();
        void initEnemyGatherer();
        void initEnemyWaves();
        FILE* serial_port;//puerto serial para lectura
        FILE* serial_port_write;//puerto serial para escritura
        xmlDoc* doc;//documento xml
        xmlNode* root_element;
};

#endif // GAME_H
