// C++ File for pf_thread

#include "pf_thread.h"

void* pf_thread( void* thread_args ) {
   pf_thread_args_t* args = (pf_thread_args_t*)thread_args;

   std::string prefix_str = "Thread ";
   prefix_str += std::to_string( args->thread_num );
   prefix_str += ": ";

   calc_pfs( &(args->pfs[0]), args->num_pfs, args->debug, prefix_str.c_str() );

   print_pfs( &(args->pfs[0]), args->num_pfs, prefix_str.c_str() );
   return NULL;
}


// end of C++ file for pf_thread
