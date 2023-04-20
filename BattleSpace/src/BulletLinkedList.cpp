#include "BulletLinkedList.h"
#include <iostream>
BulletLinkedList::BulletLinkedList()
    {
        head = nullptr;

        size =0;
    }
//funcion que agrega un elemento a la lista
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
//funcion que borra el primer elemento de la lista
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
//funcion que retorna un puntero a la primera bala de la lista y la saca de dicha lista
Bullet* BulletLinkedList:: removeFirstPTR(){

    if(head == nullptr){
        return nullptr;

    }

    else{

        bulletNode * Temp = head;
        Bullet* bulletPTR  = head->bullet;
        head = head->nextBullet;
        delete Temp;
        size--;
        return bulletPTR;

    }
}
//funcion que imprime todos los punteros disponibles
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
//método de renderización de balas
void BulletLinkedList::drawAll(sf::RenderTarget& target) {
        bulletNode* current = this->head;
        while (current != nullptr) {

            target.draw(current->bullet->shape);
            current = current->nextBullet;
        }
    }
//destructor
BulletLinkedList::~BulletLinkedList()
    {
        //dtor
    }

