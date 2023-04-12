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
        int size;
        enemyNode* head;
        void drawAll(sf::RenderTarget& target);
        void printList(enemyNode * head);
    protected:

    private:
};

#endif // ENEMYLINKEDLIST_H
