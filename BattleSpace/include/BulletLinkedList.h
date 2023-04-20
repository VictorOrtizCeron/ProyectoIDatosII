#ifndef BULLETLINKEDLIST_H
#define BULLETLINKEDLIST_H

#include "bulletNode.h"
#include "Bullet.h"

class BulletLinkedList
{
    public:
        BulletLinkedList();
        virtual ~BulletLinkedList();
        void addFirst(Bullet *bullet);
        void removeFirst();
        Bullet* removeFirstPTR();
        Bullet * removeBullet(Bullet * bulletToRemove);
        int size;//tamaño de lista enlazada
        bulletNode* head;
        void drawAll(sf::RenderTarget& target);
        void printList(bulletNode * head);
    protected:

    private:




};

#endif // BULLETLINKEDLIST_H
