#include "CmdLine.h"

void CmdLine::prepare(){
    sfmt_init_gen_rand(&SfmtSeed, time(NULL));
    random_device rd;
    rng.seed(rd);
}
void CmdLine::parse_cmdargs(int argc, char **argv) {
    
  for (int i=1; i<argc; i++) {

    // Create g-trie ?
    if (!strcmp("-c",argv[i]) || !strcmp("--create",argv[i])) {
      create=true;
      strcpy(subgraphs_file, argv[++i]);
    }
    
    // Graph file
    else if (!strcmp("-g",argv[i]) || !strcmp("--graph",argv[i])) {