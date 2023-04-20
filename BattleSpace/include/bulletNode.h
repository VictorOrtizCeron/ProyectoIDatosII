#ifndef BULLETNODE_H
#define BULLETNODE_H

#include "Bullet.h"


class bulletNode
{
    public:
        bulletNode();
        bulletNode(Bullet *bala);
        virtual ~bulletNode();
        bulletNode* nextBullet;//puntero a proximo elemento de la lista
        Bullet *bullet;//puntero al objeto Bullet correspondiente
    protected:




};

#endif // BULLETNODE_H
