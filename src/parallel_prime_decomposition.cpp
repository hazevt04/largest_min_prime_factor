// C++ File for parallel_prime_decomposition

#include "parallel_prime_decomposition.h"

void parallel_prime_decomposition( pf_t* largest, const int* vals, const int num_vals, const bool debug=true ) {
   
   pf_t pfs[num_vals];

   init_pfs( &(pfs[0]), &(vals[0]), num_vals );
   calc_pfs( &(pfs[0]), num_vals, debug );
   print_pfs( &(pfs[0]), num_vals, "" );   
   
   copy_pf( largest, &(pfs[0]) );
}


// end of C++ file for parallel_prime_decomposition
