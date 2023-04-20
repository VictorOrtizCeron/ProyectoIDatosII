#include "enemyNode.h"

enemyNode::enemyNode()
{
    //ctor
}
//constructor de nodo de enemigo
enemyNode::enemyNode(Enemy* enemyPTR)
{
    this->enemy = enemyPTR;
    this->nextEnemy = nullptr;
}


enemyNode::~enemyNode()
{
    //dtor
}
