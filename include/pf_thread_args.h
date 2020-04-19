#ifndef __PF_THREAD_ARGS_H__
#define __PF_THREAD_ARGS_H__

#include "pf.h"

typedef struct pf_thread_args_s {
   pf_t* pfs;
   int num_pfs;
   int thread_num;
   bool debug;
} pf_thread_args_t;

#endif // end of #ifndef __PF_THREAD_ARGS_H__
