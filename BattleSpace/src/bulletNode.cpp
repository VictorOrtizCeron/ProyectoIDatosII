#include "bulletNode.h"

bulletNode::bulletNode()
{

}
bulletNode::bulletNode(Bullet *bala)
{
    this->bullet = bala;
    this->nextBullet = nullptr;
}
bulletNode::~bulletNode()
{
    //dtor
}
