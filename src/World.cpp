#include "../include/World.h"
#include <iterator>

World::World()
{
}
World::~World()
{
    this->nodes.clear();
}
void World::createNodes()
{
    //read file to get node name, x, y
    Node nod0, nod1;
    nod0.addNode(0, 0, 0);
    std::cout<<"node name: "<<nod0.getName()<<std::endl;
    nod1.addNode(1, 1, 3);
    //read node edges
    std::list<int> rEdge;
    rEdge.push_back(11);
    //add edges to node
    nod0.addEdges(rEdge);
    nod1.addEdges(rEdge);
    //create edge
    //avoid double edges
    for ( auto i = rEdge.begin(); i != rEdge.end(); i++)
    {
        std::cout<<"Edge name: "<<i.operator*()<<std::endl;
        auto it = this->edges.find(i.operator*());
        if (it == this->edges.end())
        {
            Edge e;
            e.createEdge(i.operator*());
            this->edges[i.operator*()] = e;
            std::cout<<"creating edge"<<std::endl;
        }
    }

    //add nodes in container
    this->nodes[0] = nod0;
    this->nodes[1] = nod1;

    //connect
    for (auto i = this->nodes.begin(); i != this->nodes.end(); i++)
    {
        std::list<int> lista;
        i->second.returnEdges(lista);
        for (auto j = lista.begin(); j != lista.end(); j++)
        {
           auto it = this->edges.find(j.operator*());
           if (it != this->edges.end())
           {
               if (it->second.connected == false)
               {
                    it->second.connected = true;
                    it->second.pointA = i->second.getName();
               }
               else
               {
                   it->second.pointB = i->second.getName();
               }
           }
        }
    }
    for ( auto i = this->edges.begin(); i != this->edges.end(); i++)
    {
        std::cout<<"edge name: "<<i->first<<" Point A: "<<i->second.pointA<<" Point B: "<<i->second.pointB<<std::endl;
    }

}
