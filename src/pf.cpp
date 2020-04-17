// C++ File for pf

#include "pf.h"

void gen_pfs( pf_t* pfs, const int num_pfs ) {
   int range = 1000;
   int lower = 0;
   for( int index = 0; index < num_pfs; index++ ) {
      pfs[ index ].val = (int)(rand() % (int)range) + lower;
      pfs[ index ].num_prime_factors = 1;
   } 
}

void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug = false ) {
   for( int index = 0; index < num_pfs; index++ ) {
      prime_decomposition( &(pfs[index].prime_factors[0]), &(pfs[index].num_prime_factors), pfs[index].val, debug );
   } 
}


void print_pf( const pf_t* pf, const char* prefix="" ) {
   printf( "%s%d: { ", prefix, pf->val );
   for( int index = 0; index < pf->num_prime_factors; index++ ) {
      printf( "%d%s", pf->prime_factors[ index ], 
         ( ( index < pf->num_prime_factors - 1 ) ? "," : "" ) ); 
   }
   printf( " }\n" ); 
   
}

void print_pfs( const pf_t* pfs, const int num_pfs, const char* prefix="" ) {
   for( int index = 0; index < num_pfs; index++ ) {
      printf( "%s%d: { ", prefix, pfs[index].val );
      for( int inner_index = 0; inner_index < pfs[index].num_prime_factors; inner_index++ ) {
         printf( "%d%s", pfs[index].prime_factors[ inner_index ], 
            ( ( inner_index < pfs[index].num_prime_factors - 1 ) ? "," : "" ) ); 
      }
      printf( " }\n" ); 
   } 
   
}
// end of C++ file for pf
