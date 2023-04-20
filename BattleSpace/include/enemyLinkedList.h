#ifndef ENEMYLINKEDLIST_H
#define ENEMYLINKEDLIST_H

#include "enemyNode.h"
#include "Enemy.h"

class enemyLinkedList
{
    public:
        enemyLinkedList();
        virtual ~enemyLinkedList();
        void addFirst(Enemy *enemyPTR);
        Enemy * removeEnemy(Enemy * EnemyToRemove);
        int size;//tamaño de lista enlazada
        enemyNode* head;
        void drawAllEnemies(sf::RenderTarget& target);
        void printList(enemyNode * head);
        Enemy* removeFirst();


    protected:

    private:
};

#endif // ENEMYLINKEDLIST_H
