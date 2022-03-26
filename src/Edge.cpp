#include "../include/Edge.h"

Edge::Edge()
{
}
Edge::~Edge()
{
}

void Edge::createEdge(int name)
{
    this->name = name;
}

int Edge::getName()
{
    return this->name;
}
