#include "BulletLinkedList.h"

BulletLinkedList::BulletLinkedList()
    {
        head = nullptr;

        size =0;
    }

void BulletLinkedList::addFirst(Bullet *bullet){

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

void BulletLinkedList:: removeFirst(){

    if(head == nullptr){
        return;

    }

    else{

        bulletNode *Temp  = head;
        head = head->nextBullet;
        delete Temp;
        size--;
    }
}

BulletLinkedList::~BulletLinkedList()
    {
        //dtor
    }

