// C++ File for pf

#include "pf.h"

// Initialize an array of pfs from an array of ints
// Assumes pfs is already allocated
void init_pfs( pf_t* pfs, const int* __restrict__ vals, const int num_vals ) {
   for( int index = 0; index < num_vals; index++ ) {
      pfs[ index ].val = vals[ index ];
      pfs[ index ].num_prime_factors = 1;
   } 
}


// Generate random numbers for pfs
void gen_pfs( pf_t* pfs, const int num_pfs ) {
   int range = 1000;
   int lower = 0;
   srand(time(NULL));
   for( int index = 0; index < num_pfs; index++ ) {
      pfs[ index ].val = (int)(rand() % (int)range) + lower;
      pfs[ index ].num_prime_factors = 1;
   } 
}

// Calculate prime factors for each pf in the array of pfs
void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug = false ) {
   for( int index = 0; index < num_pfs; index++ ) {
      prime_decomposition( &(pfs[index].prime_factors[0]), &(pfs[index].num_prime_factors), pfs[index].val, debug );
   } 
}

// print one pf
void print_pf( const pf_t* __restrict__ pf, const char* __restrict__ prefix="" ) {
   printf( "%s%d: { ", prefix, pf->val );
   for( int index = 0; index < pf->num_prime_factors; index++ ) {
      printf( "%d%s", pf->prime_factors[ index ], 
         ( ( index < pf->num_prime_factors - 1 ) ? "," : "" ) ); 
   }
   printf( " }\n" ); 
}

// Copies from pf pointed to by src to pf pointed to by dest
// pf_t struct has an array which requires a deep copy, done here
void copy_pf( pf_t* dest, const pf_t* src ) {
   dest->val = src->val;
   dest->num_prime_factors = src->num_prime_factors;
   for( int index = 0; index < src->num_prime_factors; index++ ) {
      dest->prime_factors[index] = src->prime_factors[index];
   } 
}

// print an array of pfs
void print_pfs( const pf_t*  __restrict__ pfs, const int num_pfs, const char* __restrict__ prefix="" ) {
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
