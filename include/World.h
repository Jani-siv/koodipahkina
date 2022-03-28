#pragma once

#include "Edge.h"
#include "Node.h"
#include <list>
#include <map>
#include <iostream>
#include <fstream>
class World : public Edge, Node {
    public:
        World();
        ~World();
        void createNodes(int name,int x,int y,std::list<int> edgeNames);
        void getEdgesCoordinates(std::map<int,std::map<int,int>>&startCoordinate,std::map<int,std::map<int,int>>&endCoordinates);
        void getNodesCoordinates(std::map<int,std::map<int,int>>&nodeCoordinates);
        
        void jsonParser(std::string filename);
    private:
        void connectEdges();
        void createEdgesForContainer(std::list<int> edge);
        std::map<Edge,std::map<Node,Node>>connection;
        std::map<int,Node> nodes;
        std::map<int,Edge> edges;

};
