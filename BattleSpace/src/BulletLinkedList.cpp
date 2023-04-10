#include "BulletLinkedList.h"
#include <iostream>
BulletLinkedList::BulletLinkedList()
    {
        head = nullptr;

        size =0;
    }

void BulletLinkedList::addFirst(Bullet *bullet){

        //printf("%x",bullet);
        bulletNode* newNode = new bulletNode(bullet);
        if(head == nullptr){
            this->head = newNode;


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


void BulletLinkedList:: printList(bulletNode *head){
    bulletNode *current = head;
    std::cout<<"Resultado PrintList: "<<std::endl;
    while(current != nullptr){

        std::cout<<current->bullet<<std::endl;
        current = current->nextBullet;
    }
}

//este metodo no borra el puntero, solo lo saca de shotBullets
Bullet* BulletLinkedList:: removeBullet(Bullet* bulletToRemove){

    bulletNode* current = this->head;
    bulletNode* previous = nullptr;

    while (current != nullptr) {
        if (current->bullet == bulletToRemove) {

            // Found the node to remove
            if (previous == nullptr) {

                // Removing the head node
                this->head = current->nextBullet;
                size--;

                return current->bullet;
            } else {
                previous->nextBullet = current->nextBullet;
                size--;
                return current->bullet;
            }

        }

        // Move to next node
        previous = current;
        current = current->nextBullet;
    }
}

void BulletLinkedList::drawAll(sf::RenderTarget& target) {
        bulletNode* current = this->head;
        while (current != nullptr) {

            target.draw(current->bullet->shape);
            current = current->nextBullet;
        }
    }

BulletLinkedList::~BulletLinkedList()
    {
        //dtor
    }

