#ifndef _Sample_
#define _Sample_


#include "Common.h"
#include "Timer.h"
#include "Random.h"

class Sample{
    private:
    vector<vector<int> > sample_count;  //图元采样计数，访问次数
    vector<vector<double> > weight_count;   //图元采样权重计数
    vector<int> weight;     //图元权重，每种采样方法不同
    int _set_repeat_time; //重复独立实验次数
    int _set_sample_num;  //单次实验采样次数
    int _set_step=1;  //jump 长度,默认为1
    bool _count_nrmse_mode=false; //nrmse计算模式，0为全部计数，1为断点计数
    int _nrmse_width; //断点计数长度

    public:
    void init(int set_repeat_time,int set_sample_num):_set_repeat_time(set_repeat_time),_set_sample_num(set_sample_num);
    void init(int set_repeat_time,int set_sample_num, int set_step):_set_repeat_time(set_repeat_time),_set_sample_num(set_sample_num),_set_step(set_step);
    void setNrmseMode(int nrmse_width):_count_nrmse_mode(true),_nrmse_width(nrmse_width);
    void run(Graph *G);
    
    virtual void sample_once(Graph *G);
    virtual void test();
};
#endif 