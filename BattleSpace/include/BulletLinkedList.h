#ifndef BULLETLINKEDLIST_H
#define BULLETLINKEDLIST_H

#include "bulletNode.h"
#include "Bullet.h"

class BulletLinkedList
{
    public:
        BulletLinkedList();
        virtual ~BulletLinkedList();
        void addFirst(Bullet bullet);
        void removeFirst();
        int size;

    protected:

    private:

        bulletNode* head;


};

#endif // BULLETLINKEDLIST_H