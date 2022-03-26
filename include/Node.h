#pragma once
#include <list>
class Node{
    public:
        Node();
        ~Node();
        void addNode(int name, int x, int y);
        void addEdges(std::list<int>edges);
        void returnEdges(std::list<int>&lista);
        int getName();
    private:
        int name;
        typedef struct coordinates{
            int x;
            int y;
        }coordinates;
        coordinates coord;
        std::list<int> edgeList;
};

