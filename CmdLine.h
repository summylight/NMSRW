#ifndef _CMDLINE_
#define _CMDLINE_

#include "Graph.h"
#include "Graphlet.h"
#include "Sample.h"
#include "Nrmse.h"
#include "Random.h"
#include "Common.h"
#include "Timer.h"
using namespace std;
class CmdLine{
    private:
        static char graph_file[MAX_BUF];
        static int motif_size;
        static char graph_dir[MAX_BUF];

        
        static MethodType method;
        static bool runnrmse;
        static bool multi_thread;

        static int motif_size;
        static int thread_num;
        

        unordered_map<string,int> Test_File;
    public:


};

#endif _CMDLINE_
