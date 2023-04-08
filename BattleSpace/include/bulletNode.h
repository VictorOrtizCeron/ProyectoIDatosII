#ifndef BULLETNODE_H
#define BULLETNODE_H

#include "Bullet.h"


class bulletNode
{
    public:
        bulletNode();
        bulletNode(Bullet bala);
        virtual ~bulletNode();
        bulletNode* getNext();
    protected:


    private:
        bulletNode* nextBullet;
        Bullet bullet;
};

#endif // BULLETNODE_H
