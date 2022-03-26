#pragma once

class Edge{
    public:
        Edge();
        ~Edge();
        void createEdge(int name);
        int getName();
        bool connected = false;
        int pointA;
        int pointB;
    private:
        double length;
        int name;
        typedef struct points{
            int pointAx;
            int pointAy;
            int pointBx;
            int pointBy;
        }points;
        points coord;
};
