#include "enemyNode.h"

enemyNode::enemyNode()
{
    //ctor
}
enemyNode::enemyNode(Enemy* enemyPTR)
{
    this->enemy = enemyPTR;
    this->nextEnemy = nullptr;
}


enemyNode::~enemyNode()
{
    //dtor
}
