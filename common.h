/*
include一些常用的标准库和igraph库等
*/



#ifndef _COMMON_
#define _COMMON_

#include<igraph.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include "SFMT/SFMT.h"


#define MAX_BUF 1024 //Maximum string buffer size
#define SEPARATOR "-------------------------------------------------"
#define MOTIF5_NUM 21
#define MOTIF4_NUM 6
#define MOTIF6_NUM 112
#define MOTIF7_NUM 853

#define MIN_MOTIF_SIZE 5
#define MAX_MOTIF_SIZE 7
using namespace std;


typedef unordered_map<string, int> mapStringInt;


/**
 * \function print_vector
 * Print elements in an igraph vector  
 * 
 * \param vector pointer
 * \param outfile FILE pointer (using stdout can print to the screen)
 * 
 * */
void print_ivector(igraph_vector_t *v, FILE *f) {
  long int i;
  for (i=0; i<igraph_vector_size(v); i++) {
    fprintf(f, " %li", (long int) VECTOR(*v)[i]);
  }
  fprintf(f, "\n");
}


#endif _COMMON_
