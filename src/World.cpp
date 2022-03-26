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
    Node nod0, nod1, nod2;
    nod0.addNode(0, 0, 0);
    nod1.addNode(1, 1, 3);
    nod2.addNode(2, 2, 2);
    //read node edges
    std::list<int> rEdge0, rEdge1, rEdge2;
    rEdge0.push_back(11);
    rEdge0.push_back(13);
    
    rEdge1.push_back(11);
    rEdge1.push_back(12);

    rEdge2.push_back(12);
    rEdge2.push_back(13);

    //add edges to node
    nod0.addEdges(rEdge0);
    nod1.addEdges(rEdge1);
    nod2.addEdges(rEdge2);
    //create edge
    //avoid double edges
    this->createEdgesForContainer(rEdge0);
    this->createEdgesForContainer(rEdge1);
    this->createEdgesForContainer(rEdge2);
    //add nodes in container
    this->nodes[0] = nod0;
    this->nodes[1] = nod1;
    this->nodes[2] = nod2;

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

void World::createEdgesForContainer(std::list<int> edge)
{
   for (auto i = edge.begin(); i != edge.end(); i++)
   {
       auto it = this->edges.find(i.operator*());
       if (it == this->edges.end())
       {
           Edge e;
           e.createEdge(i.operator*());
           this->edges[i.operator*()] = e;
       }
   }
}
