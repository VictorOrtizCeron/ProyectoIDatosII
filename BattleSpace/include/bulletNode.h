#ifndef BULLETNODE_H
#define BULLETNODE_H

#include "Bullet.h"


class bulletNode
{
    public:
        bulletNode();
        bulletNode(Bullet *bala);
        virtual ~bulletNode();
        bulletNode* nextBullet;
        Bullet *bullet;
    protected:




};

#endif // BULLETNODE_H
