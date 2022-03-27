#include "../include/World.h"
#include <iterator>
#include <sstream>
#include <string>

World::World()
{
    std::cout<<"hello"<<std::endl;
    this->jsonParser("test.json");
}
World::~World()
{
    this->nodes.clear();
}

void World::jsonParser(std::string filename)
{
    //open file
    std::string line;
    std::string directory = "./data/";
    directory += filename;
    std::cout<<directory<<std::endl;
    std::ifstream inputfile(directory.c_str());
  
            size_t pos;
        int nodeNum = 0;
        bool firstNode = false;
    if (inputfile.is_open())
    {
        std::cout<<"input file is open"<<std::endl;
        while(!inputfile.eof())
        {
            std::getline(inputfile,line);
            if (firstNode == false) 
            {
                std::cout<<"trying find"<<std::endl;
                std::string comp = "\"0\"";
                pos = line.find(comp);
                std::cout<<line<<std::endl;
                if (pos < line.length())
                {
                    std::cout<<"found: "<<line<<" from pos: "<<pos<<std::endl;
                    std::getline(inputfile,line);
                    pos = line.find("x");
                    std::cout<<"found x: "<<pos<<std::endl;
                    std::getline(inputfile,line);
                    pos = line.find("y");
                    std::cout<<"found y: "<<pos<<std::endl;
                    std::getline(inputfile,line);
                    std::getline(inputfile,line);
                    pos = line.find("\"");
                    std::cout<<"found edgepoint: "<<pos<<std::endl;
                    std::getline(inputfile,line);
                    pos = line.find("\"");
                    std::cout<<"found edgepoint: "<<pos<<std::endl;
                                       
                firstNode = true;
                }
            }
            if (firstNode == true)
            {
            nodeNum++;
            }
        }
    }
}


void World::createNodes()
{
    //read file to get node name, x, y
    Node nod0, nod1, nod2;
    nod0.addNode(0, 0, 0);
    nod1.addNode(1, 100, 300);
    nod2.addNode(2, 200, 200);
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

void World::getEdgesCoordinates(std::map<int,std::map<int,int>>&startCoordinate, std::map<int,std::map<int,int>>&endCoordinates)
{
    std::map<int,int> tempCoordinates;
    int X=0,Y=0;
    for (auto i = this->edges.begin(); i != edges.end(); i++)
    {
        auto it = this->nodes.find(i->second.pointA);
        if (it != this->nodes.end())
        {
            tempCoordinates.clear();
            X = it->second.getXcoord();
            Y = it->second.getYcoord();
            tempCoordinates[X] = Y;
            startCoordinate[i->first] = tempCoordinates;
        }
        it = this->nodes.find(i->second.pointB);
        if (it != this->nodes.end())
        {
            tempCoordinates.clear();
            X = it->second.getXcoord();
            Y = it->second.getYcoord();
            tempCoordinates[X] = Y;
            endCoordinates[i->first] = tempCoordinates;
        }

    }
}

void World::getNodesCoordinates(std::map<int, std::map<int, int>> &nodeCoordinates)
{
    std::map<int,int>coord;
    for (auto it = this->nodes.begin(); it != this->nodes.end(); it++)
    {
        coord[it->second.getXcoord()] = it->second.getYcoord();
        nodeCoordinates[it->first] = coord;
        coord.clear();
    }
}
