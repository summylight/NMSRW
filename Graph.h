#ifndef _GRAPH_
#define _GRAPH_

#include "Common.h"
#include "Error.h"
#include "Random.h"
class Graph{
    private:

        int cur_node; //当前所在节点
        const static int StartSteps = 1000; //默认随机游走前1000步达到收敛
        int vcount; //图节点数
        int ecount; //图边数

    public:
        igraph_t G; //igraph数据结构，存储图，public方便调试
        Graph(const char *filename);
        ~Graph();

        void read_graph(const char *filename);
        void randWalk(int staps);
        void randStart();
        void randWalk_Converge();

        int getCur_node() const;
        int getVcount() const;
        int getEcount() const;
        int getDegree(const int node) const;
        bool get_edge_status(const int from, const int to) const;
        void printGraph() const;

        void getNeigh(const int node,igraph_vector_t *iv) const;
        void getDegrees(igraph_vector_t *nodes,igraph_vector_t *degrees) const;
        void getAllDegrees(igraph_vector_t *degrees) const;

};

#endif