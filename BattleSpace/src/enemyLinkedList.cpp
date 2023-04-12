#include "enemyLinkedList.h"

enemyLinkedList::enemyLinkedList()
{
    //ctor
}

void enemyLinkedList::addFirst(Enemy* enemyPTR){

    enemyNode* newNode = new enemyNode(enemyPTR);
        if(head == nullptr){
            this->head = newNode;

        }
        else{

            newNode -> nextEnemy = this->head;
            this -> head = newNode;


        }

        size++;


}

Enemy* enemyLinkedList::removeEnemy(Enemy* EnemyToRemove){

    enemyNode* current = this->head;
    enemyNode* previous = nullptr;

    while (current != nullptr) {
        if (current->enemy == EnemyToRemove) {

            // Found the node to remove
            if (previous == nullptr) {

                // Removing the head node
                this->head = current->nextEnemy;
                size--;

                return current->enemy;
            } else {
                previous->nextEnemy = current->nextEnemy;
                size--;
                return current->enemy;
            }

        }

        // Move to next node
        previous = current;
        current = current->nextEnemy;
    }
\

}


Enemy* enemyLinkedList::removeFirst(){

    if(this->head == nullptr){
        return nullptr;

    }

    else{

        enemyNode *Temp  = head;
        head = head->nextEnemy;

        return Temp->enemy;
        size--;
    }

}

void enemyLinkedList::drawAllEnemies(sf::RenderTarget& target) {
        enemyNode* current = this->head;
        while (current != nullptr) {

            target.draw(current->enemy->enemySprite);
            current = current->nextEnemy;
        }
    }

enemyLinkedList::~enemyLinkedList()
{
    //dtor
}
