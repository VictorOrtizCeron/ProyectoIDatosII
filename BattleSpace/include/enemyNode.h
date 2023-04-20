#ifndef ENEMYNODE_H
#define ENEMYNODE_H

#include "Enemy.h"
class enemyNode
{
    public:
        enemyNode();
        enemyNode(Enemy* enemyPTR);
        virtual ~enemyNode();
        enemyNode* nextEnemy;//punto al siguiente nodo de la lista
        Enemy* enemy;//puntero al objeto Enemy almacenado

    protected:

    private:
};

#endif // ENEMYNODE_H
