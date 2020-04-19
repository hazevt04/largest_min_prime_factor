// C++ File for pf

#include "pf.h"

#include "primes.h"

// Copies from pf pointed to by src to pf pointed to by dest
// pf_t struct has an array which requires a deep copy, done here
void copy_pf( pf_t* dest, const pf_t* src ) {
   dest->val = src->val;
   dest->num_prime_factors = src->num_prime_factors;
   for( int index = 0; index < src->num_prime_factors; index++ ) {
      dest->prime_factors[index] = src->prime_factors[index];
   } 
}


void num_primes_up_to_val( int* num_primes, const int val, const bool debug = false ) {
   int prime_index = 0;
   while( primes[prime_index] <= val ) {
      ++prime_index;
   } 
   *num_primes = prime_index;
}


// Calculate prime factors for the val in pf
void calc_pf( pf_t* pf, const bool debug = false, const char* prefix = "" ) {
   int num_t_primes = 0;

   num_primes_up_to_val( &num_t_primes, pf->val, debug );
   debug_printf( debug, "%sNumber of primes up to %d is %d\n", prefix, pf->val, num_t_primes ); 

   int t_val = pf->val;
   int p_index = 0;
   int pf_index = 0;
   while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
      if ( divides( t_val, primes[ p_index ] ) ) {
         debug_printf( debug, "%s(): %sTemp Val is %d\n", __func__, prefix, t_val ); 
         debug_printf( debug, "%s(): %sPrimes[ %d ] is %d\n", __func__, prefix, p_index, primes[ p_index ] );
         debug_printf( debug, "%s(): %sTemp Val was divisible by that prime. It is a prime factor\n\n", __func__, prefix ); 
         pf->prime_factors[ pf_index ] = primes[ p_index ];
         t_val = t_val/primes[ p_index ];
         pf_index++;
      } else {
         debug_printf( debug, "%s(): %sTemp Val, %d, is not divisible by prime %d, %d. Prime index incremented.\n\n", __func__, 
            prefix, t_val, p_index, primes[ p_index ] ); 
         p_index++;
      }
   } // end of while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
   
   pf->num_prime_factors = pf_index;
   
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
   int lower = 2;
   srand(time(NULL));
   for( int index = 0; index < num_pfs; index++ ) {
      pfs[ index ].val = (int)(rand() % (int)range) + lower;
      pfs[ index ].num_prime_factors = 1;
   } 
}


// Calculate prime factors for each pf in the array of pfs
void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug = false, const char* prefix = "" ) {
   for( int index = 0; index < num_pfs; index++ ) {
      calc_pf( &(pfs[index]), debug, prefix );
   } 
}


// print an array of pfs
void print_pfs( const pf_t*  __restrict__ pfs, const int num_pfs, const char* __restrict__ prefix="" ) {
   for( int index = 0; index < num_pfs; index++ ) {
      printf( "%s%d) %d: { ", prefix, index, pfs[index].val );
      for( int inner_index = 0; inner_index < pfs[index].num_prime_factors; inner_index++ ) {
         printf( "%d%s", pfs[index].prime_factors[ inner_index ], 
            ( ( inner_index < pfs[index].num_prime_factors - 1 ) ? "," : "" ) ); 
      }
      printf( " }\n" ); 
   } 
}

// end of C++ file for pf
