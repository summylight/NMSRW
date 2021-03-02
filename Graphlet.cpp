#include "Graphlet.h"
/**
 * @brief 度数排序返回5节点图对应图元编号
 * 
 * @param G 5节点连通无环无向图
 * @return int 返回图元编号
 */
int Graphlet::get_graphletid5(const Graph &G)
{
    igraph_vector_t v;
    igraph_vector_init(&v,0);
    G.getAllDegrees(&v);
    int degree[5];
    vector<int> copy_degree(5);
    int id;
    for (int i = 0; i < 5; i++)
    {
        degree[i] = VECTOR(v)[i];
    }
    copy_degree[0] = degree[0];
    copy_degree[1] = degree[1];
    copy_degree[2] = degree[2];
    copy_degree[3] = degree[3];
    copy_degree[4] = degree[4];
    sort(degree, degree + 5);

    if (degree[0] == 1 && degree[1] == 1 && degree[2] == 2 && degree[3] == 2 && degree[4] == 2)
    {
        id = 8;
    }
    else if (degree[0] == 1 && degree[1] == 1 && degree[2] == 1 && degree[3] == 2 && degree[4] == 3)
    {
        id = 1;
    }
    else if (degree[0] == 1 && degree[1] == 1 && degree[2] == 1 && degree[3] == 1 && degree[4] == 4)
    {
        id = 0;
    }
    else if (degree[0] == 1 && degree[1] == 1 && degree[2] == 2 && degree[3] == 3 && degree[4] == 3)
    {
        id = 4;
    }

    else if (degree[0] == 1 && degree[1] == 2 && degree[2] == 2 && degree[3] == 2 && degree[4] == 3)
    {
        int index;
        for (int i = 0; i < copy_degree.size(); i++)
        {
            if (copy_degree[i] == 1)
            {
                index = i;
                break;
            }
        }
        for (int j = 0; j < copy_degree.size(); j++)
        {
            if (index == j)
                continue;
            if (G.get_edge_status( index, j))
            {
                index = j;
                break;
            }
        }
        if (copy_degree[index] == 2)
            id = 9;
        else
            id = 3;
    }
    else if (degree[0] == 1 && degree[1] == 1 && degree[2] == 2 && degree[3] == 2 && degree[4] == 4)
    {
        id = 2;
    }

    if (degree[0] == 2 && degree[1] == 2 && degree[2] == 2 && degree[3] == 2 && degree[4] == 2)
    {
        id = 11;
    }
    else if (degree[0] == 1 && degree[1] == 2 && degree[2] == 2 && degree[3] == 3 && degree[4] == 4)
    {
        id = 5;
    }
    else if (degree[0] == 2 && degree[1] == 2 && degree[2] == 2 && degree[3] == 2 && degree[4] == 4)
    {
        id = 10;
    }
    else if (degree[0] == 1 && degree[1] == 2 && degree[2] == 3 && degree[3] == 3 && degree[4] == 3)
    {
        id = 14;
    }

    else if (degree[0] == 2 && degree[1] == 2 && degree[2] == 2 && degree[3] == 3 && degree[4] == 3)
    {
        int index;
        vector<int> _index;
        for (int i = 0; i < copy_degree.size(); i++)
        {
            if (copy_degree[i] == 3)
            {
                index = i;
                break;
            }
        }
        for (int j = 0; j < copy_degree.size(); j++)
        {
            if (index == j)
                continue;
            if (G.get_edge_status( index, j))
            {
                _index.push_back(j);
                //break;
            }
        }
        if (copy_degree[_index[0]] == 2 && copy_degree[_index[1]] == 2 && copy_degree[_index[2]] == 2)
            id = 6;
        else
            id = 12;
    }
    else if (degree[0] == 2 && degree[1] == 2 && degree[2] == 2 && degree[3] == 4 && degree[4] == 4)
    {
        id = 7;
    }

    if (degree[0] == 1 && degree[1] == 3 && degree[2] == 3 && degree[3] == 3 && degree[4] == 4)
    {
        id = 15;
    }
    else if (degree[0] == 2 && degree[1] == 2 && degree[2] == 3 && degree[3] == 3 && degree[4] == 4)
    {
        id = 13;
    }
    else if (degree[0] == 2 && degree[1] == 3 && degree[2] == 3 && degree[3] == 3 && degree[4] == 3)
    {
        id = 17;
    }
    else if (degree[0] == 2 && degree[1] == 3 && degree[2] == 3 && degree[3] == 4 && degree[4] == 4)
    {
        id = 16;
    }

    else if (degree[0] == 3 && degree[1] == 3 && degree[2] == 3 && degree[3] == 3 && degree[4] == 4)
    {
        id = 18;
    }
    else if (degree[0] == 3 && degree[1] == 3 && degree[2] == 4 && degree[3] == 4 && degree[4] == 4)
    {
        id = 19;
    }
    else if (degree[0] == 4 && degree[1] == 4 && degree[2] == 4 && degree[3] == 4 && degree[4] == 4)
    {
        id = 20;
    }
    return id;
}
/**
 * @brief 度数排序返回4节点图对应图元编号
 * 
 * @param G 4节点连通无环无向图
 * @return int 返回图元编号
 */
int Graphlet::get_graphletid4(const Graph &G){
        igraph_vector_t v;
    igraph_vector_init(&v,0);
    G.getAllDegrees(&v);
    igraph_vector_sort(&v);
    int id = -1;
    if(VECTOR(v)[0]==1 && VECTOR(v)[1]==1 && VECTOR(v)[2]==1 && VECTOR(v)[3]==3){
        id = 0;
    }
    else if(VECTOR(v)[0]==1 && VECTOR(v)[1]==1 && VECTOR(v)[2]==2 && VECTOR(v)[3]==2){
        id = 1;
    }
    else if(VECTOR(v)[0]==1 && VECTOR(v)[1]==2 && VECTOR(v)[2]==2 && VECTOR(v)[3]==3){
        id = 2;
    }
    else if(VECTOR(v)[0]==2 && VECTOR(v)[1]==2 && VECTOR(v)[2]==2 && VECTOR(v)[3]==2){
        id = 3;
    }
    else if(VECTOR(v)[0]==2 && VECTOR(v)[1]==2 && VECTOR(v)[2]==3 && VECTOR(v)[3]==3){
        id = 4;
    }
    else if(VECTOR(v)[0]==3 && VECTOR(v)[1]==3 && VECTOR(v)[2]==3 && VECTOR(v)[3]==3){
        id = 5;
    }
    return id;
}