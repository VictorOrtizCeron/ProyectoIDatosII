#include "bulletNode.h"

bulletNode::bulletNode()
{

}
//constructor de nodo de bala
bulletNode::bulletNode(Bullet *bala)
{
    this->bullet = bala;
    this->nextBullet = nullptr;
}
bulletNode::~bulletNode()
{
    //dtor
}
