#include "../include/Node.h"

Node::Node()
{
}
Node::~Node()
{
}
void Node::addNode(int name, int x, int y)
{
    this->coord.x = x;
    this->coord.y = y;
    this->name = name;
}

void Node::addEdges(std::list<int>edges)
{
    this->edgeList.assign(edges.begin(),edges.end());
}

void Node::returnEdges(std::list<int>&lista)
{
    lista.assign(this->edgeList.begin(),this->edgeList.end());
}
int Node::getName()
{
    return this->name;
}

int Node::getXcoord()
{
    return this->coord.x;
}

int Node::getYcoord()
{
    return this->coord.y;
}

