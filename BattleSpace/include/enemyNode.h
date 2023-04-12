#ifndef ENEMYNODE_H
#define ENEMYNODE_H

#include "Enemy.h"
class enemyNode
{
    public:
        enemyNode();
        enemyNode(Enemy* enemyPTR);
        virtual ~enemyNode();
        enemyNode* nextEnemy;
        Enemy* enemy;

    protected:

    private:
};

#endif // ENEMYNODE_H
