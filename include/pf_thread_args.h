#ifndef __PF_THREAD_ARGS_H__
#define __PF_THREAD_ARGS_H__

#include "pf.h"

typedef struct pf_thread_args_s {
   pf_t* pfs;
   int largest_min_prime_factor;
   int num_pfs;
   int thread_num;
   bool use_alt_imp;
   bool debug;
} pf_thread_args_t;

#endif // end of #ifndef __PF_THREAD_ARGS_H__
