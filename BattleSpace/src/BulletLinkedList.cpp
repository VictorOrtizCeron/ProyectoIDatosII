#include "BulletLinkedList.h"

BulletLinkedList::BulletLinkedList()
    {
        head = nullptr;

        size =0;
    }

void BulletLinkedList::addFirst(Bullet bullet){

        bulletNode* newNode = new bulletNode(bullet);
        if(head == nullptr){
            this->head == newNode;

        }
        else{

            newNode -> nextBullet = this->head;
            this -> head = newNode;


        }
        size++;

    }

BulletLinkedList::~BulletLinkedList()
    {
        //dtor
    }

