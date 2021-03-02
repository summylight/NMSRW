#include "Graph.h"
Graph::Graph(const char *filename)
{
    cur_node = 0;

    FILE *input = fopen(filename, "r");
    if (!input)
    {
        Error::msg("Fail to open this file: %s", filename);
    }

    cout << "Now read graph info from" << filename << endl;
    igraph_read_graph_ncol(&G, input, NULL, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_UNDIRECTED);
    vcount = igraph_vcount(&G);
    ecount = igraph_ecount(&G);
    return;
}
Graph::~Graph()
{
    igraph_destroy(&G);
    return;
}
/**
 * @brief 读取图文件
 * 
 * @param filename 读取文件路径
 */
void Graph::read_graph(const char *filename)
{
    FILE *input = fopen(filename, "r");

    if (!input)
    {
        Error::msg("Fail to open this file: %s", filename);
    }

    cout << "Now read graph info from" << filename << endl;
    igraph_read_graph_ncol(&G, input, NULL, 0, IGRAPH_ADD_WEIGHTS_NO, IGRAPH_UNDIRECTED);
    vcount = igraph_vcount(&G);
    ecount = igraph_ecount(&G);
    return;
}

/**
 * \function 随机游走steps步数
 * 
 * \param steps 随机游走步数
 * */
inline void Graph::randWalk(int steps)
{
    igraph_vector_t iv;
    igraph_vector_init(&iv, 0);

    for (int i = 0; i < steps; i++)
    {
        getNeigh(cur_node, &iv);
        int pos = Random::get_random(igraph_vector_size(&iv));
        cur_node = VECTOR(iv)[pos];
    }
    return;
}
/**
 * @brief 初始随机游走，起始点为随机点，游走步数为StartSteps
 * 
 */
void Graph::randStart()
{
    int vcount = getVcount();
    cur_node = Random::get_random(vcount);
    randWalk(StartSteps);
}
/**
 * @brief 随机游走至收敛，功能待实现
 * 
 */
void Graph::randWalk_Converge() {}

/**
 * @brief 返回目前所在节点
 * 
 * @return int 目前所在节点
 */
inline int Graph::getCur_node() const
{
    return cur_node;
}

/**
 * @brief 返回该图所有节点数目
 * 
 * @return int 节点数目
 */
inline int Graph::getVcount() const 
{
    return vcount;
}
/**
 * @brief 返回该图所有边数目
 * 
 * @return int 边数目
 */
inline int Graph::getEcount() const
{
    return ecount;
}
/**
 * @brief 返回指定节点度数
 * 
 * @param node 指定节点编号
 * @return int 指定节点度数
 */
inline int Graph::getDegree(const int node) const
{
    igraph_vs_t vids;
    igraph_vs_adj(&vids, node, IGRAPH_ALL);
    igraph_integer_t degree;
    igraph_vs_size(&G, &vids, &degree);
    return degree;
}

/**
 * @brief 得到指定节点所有邻居
 * 
 * @param node 指定节点编号
 * @param neis 邻居数组，需初始化
 */
inline void Graph::getNeigh(const int node, igraph_vector_t *neis) const 
{
    igraph_neighbors(&G, neis, node, IGRAPH_ALL);
    return;
}

/**
 * @brief 得到节点数组中所有节点的度数
 * 
 * @param nodes 节点数组
 * @param degrees 节点度数存放数组，需初始化
 */
inline void Graph::getDegrees(igraph_vector_t *nodes, igraph_vector_t *degrees) const 
{
    igraph_vs_t vids;
    igraph_vs_vector(&vids, nodes);
    igraph_degree(&G, degrees, vids, IGRAPH_ALL, 0);
    return;
}

/**
 * @brief 得到图中所有节点度数
 * 
 * @param degrees 节点度数存放数组，需初始化
 */
inline void Graph::getAllDegrees(igraph_vector_t *degrees) const 
{
    igraph_degree(&G, degrees, igraph_vss_all(), IGRAPH_OUT, IGRAPH_NO_LOOPS);
    return;
}
/**
 * @brief 判断from/to边是否存在
 * 
 * @param from 起始点
 * @param to 终点
 * @return true 起始点到终点边存在
 * @return false 边不存在
 */
inline bool Graph::get_edge_status(const int from, const int to) const 
{
    igraph_integer_t eid;
    igraph_get_eid(&G, &eid, from, to, IGRAPH_UNDIRECTED, 0);
    if (eid == -1)
        return false;
    else
        return true;
}
/**
 * @brief 打印图中所有边
 * 
 */
void Graph::printGraph() const 
{
    cout << "Now print the graph edge:" << endl;
    igraph_integer_t from, to;
    for (int k = 0; k < igraph_ecount(&G); k++)
    {
        igraph_edge(&G, k, &from, &to);
        printf(" Num %d edge : from %d to %d\n", k, from, to);
    }
    return;
}