// C++ File for main

#include "pf.h"
#include "parallel_prime_decomposition.h"

void usage( const char* prog_name ) {
   printf( "Usage: %s <number of random values>\n", prog_name );
   printf( "\tReturns list of prime numbers which\n" );
   printf( "\twhen all multiplied together, are\n" );
   printf( "\tequal to that number.\n" ); 
}

int main( int argc, char** argv ) {
   int num_pfs = 1;
   bool debug = false;
   char* end_ptr = NULL;
   if ( argc > 1 ) {
      num_pfs = strtol( argv[1], &end_ptr, 10 );
      if ( *end_ptr != '\0' ) {
         printf( "ERROR: Invalid input: %s\n", argv[1] ); 
         usage( argv[0] );
         exit( EXIT_FAILURE );
      }
   } // end of if ( argc > 1 )

   // pf_t pfs[num_pfs];
   //
   // gen_pfs( &(pfs[0]), num_pfs );
   // calc_pfs( &(pfs[0]), num_pfs, debug );
   // print_pfs( &(pfs[0]), num_pfs, "" );
   pf_t val_with_largest_min_pf;

   int vals[num_pfs];
   gen_vals<int>( &(vals[0]), 0, 1000, num_pfs );

   parallel_prime_decomposition( &val_with_largest_min_pf, &(vals[0]), num_pfs, debug ); 

   exit( EXIT_SUCCESS );
}


