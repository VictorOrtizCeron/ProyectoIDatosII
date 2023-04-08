#ifndef BULLETLINKEDLIST_H
#define BULLETLINKEDLIST_H

#include "bulletNode.h"

class BulletLinkedList
{
    public:
        BulletLinkedList();
        virtual ~BulletLinkedList();
        void addFirst();
        void removeFirst();
        int getSize();

    protected:

    private:
        int size;
        bulletNode* head;


};

#endif // BULLETLINKEDLIST_H
