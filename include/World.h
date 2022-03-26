#pragma once

#include "Edge.h"
#include "Node.h"
#include <list>
#include <map>
#include <iostream>
class World : public Edge, Node {
    public:
        World();
        ~World();
        void createNodes();
    private:
        void createEdgesForContainer(std::list<int> edge);
        std::map<Edge,std::map<Node,Node>>connection;
        std::map<int,Node> nodes;
        std::map<int,Edge> edges;

};
