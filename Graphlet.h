#ifndef _GRAPHLET_
#define _GRAPHLET_

#include "Common.h"
#include "Graph.h"
/**
 * @brief 
 * 
 */
class Graphlet{
    public:
        static int get_graphletid5(const Graph &G);
        static int get_graphletid4(const Graph &G);
        int get_graphletid6(const Graph &G);
        int get_graphletid7(const Graph &G);
        void init_check(int motif_size);

    private:
        int motif_size;
        vector<vector<bool> > motif_check;
};

#endif