// C++ File for pf

#include "pf.h"

// Copies from pf pointed to by src to pf pointed to by dest
// pf_t struct has an array which requires a deep copy, done here
void copy_pf( pf_t* dest, const pf_t* src ) {
   dest->val = src->val;
   dest->num_prime_factors = src->num_prime_factors;
   for( int index = 0; index < src->num_prime_factors; index++ ) {
      dest->prime_factors[index] = src->prime_factors[index];
   } 
}


// Calculate prime factors for the val in pf
void calc_pf( pf_t* pf, const bool debug = false, const char* __restrict__ prefix = "" ) {
   int num_t_primes = 0;

   int t_val = pf->val;
   int t_div = 2;
   int p_index = 0;
   int pf_index = 0;
   while( t_val > 1 ) {
      if ( divides( t_val, t_div ) ) {
         debug_printf( debug, "%s(): %sTemp Val is %d\n", __func__, prefix, t_val ); 
         debug_printf( debug, "%s(): %sTemp Divisor is %d\n", __func__, prefix, t_div );
         debug_printf( debug, "%s(): %sTemp Val was divisible by that divisor. It is a prime factor\n\n", __func__, prefix ); 
         pf->prime_factors[ pf_index++ ] = t_div;
         t_val = t_val/t_div;
      } else {
         debug_printf( debug, "%s(): %sTemp Val, %d, is not divisible by the divisor %d, Prime index incremented.\n\n", __func__, 
            prefix, t_val, t_div ); 
         t_div++;
      }
   } // end of while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
   
   pf->num_prime_factors = pf_index;
   
}


// Calculate prime factors for each pf in the array of pfs
void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug = false, const char* __restrict__ prefix = "" ) {
   for( int index = 0; index < num_pfs; index++ ) {
      int p_index = 0;
      int pf_index = 0;
      int num_t_primes = 0;

      int t_val = pfs[index].val;
      int t_div = 2;
      while( t_val > 1 ) {
         if ( divides( t_val, t_div ) ) {
            debug_printf( debug, "%s(): %sTemp Val is %d\n", __func__, prefix, t_val ); 
            debug_printf( debug, "%s(): %sTemp Divisor is %d\n", __func__, prefix, t_div );
            debug_printf( debug, "%s(): %sTemp Val was divisible by that divisor. It is a prime factor\n\n", __func__, prefix ); 
            pfs[index].prime_factors[ pf_index ] = t_div;
            t_val = t_val/t_div;
            pf_index++;
         } else {
            debug_printf( debug, "%s(): %sTemp Val, %d, is not divisible by divisor %d. Prime index incremented.\n\n", __func__, 
               prefix, t_val, t_div ); 
            t_div++;
         }
      } // end of while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
      pfs[index].num_prime_factors = pf_index;
   } // end of for( int index = 0; index < num_pfs; index++ ) {
}

// For each pf_t, only find ONE prime factor, which will be the minimum prime factor!
void calc_min_pfs( pf_t* pfs, const int num_pfs, const bool debug = false, const char* __restrict__ prefix = "" ) {
   for( int index = 0; index < num_pfs; index++ ) {
      int p_index = 0;
      int pf_index = 0;
      int num_t_primes = 0;

      int t_val = pfs[index].val;
      int t_div = 2;
      while( t_val > 1 ) {
         if ( divides( t_val, t_div ) ) {
            debug_printf( debug, "%s(): %sTemp Val is %d\n", __func__, prefix, t_val ); 
            debug_printf( debug, "%s(): %sTemp Divisor is %d\n", __func__, prefix, t_div );
            debug_printf( debug, "%s(): %sTemp Val was divisible by that divisor. It is a prime factor\n\n", __func__, prefix ); 
            pfs[index].prime_factors[ pf_index ] = t_div;
            t_val = t_val/t_div;
            pf_index++;
            break;
         } else {
            debug_printf( debug, "%s(): %sTemp Val, %d, is not divisible by divisor %d. Prime index incremented.\n\n", __func__, 
               prefix, t_val, t_div ); 
            t_div++;
         }
      } // end of while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
      pfs[index].num_prime_factors = 1;
   } // end of for( int index = 0; index < num_pfs; index++ ) {
   
}


void find_largest_min_pf( int* largest_min_pf, pf_t* pfs, const int num_pfs, const bool debug = false, 
      const char* __restrict__ prefix = "" ) {
   pf_t* largest_ptr = &pfs[0];
   for( int index = 1; index < num_pfs; index++ ) {
      debug_printf( debug, "%s(): %slargest_min_pf prime_factors[0] = %d\n",
         __func__, prefix, largest_ptr->prime_factors[0] ); 
      debug_printf( debug, "%s(): %spfs[%d].prime_factors[0] = %d\n",
         __func__, prefix, index, pfs[index].prime_factors[0] ); 
      if ( pfs[index].prime_factors[0] > largest_ptr->prime_factors[0] ) {
         largest_ptr = &pfs[index];
         debug_printf( debug, "%s(): %s\tNEW largest_min_pf prime_factors[0] = %d",
            __func__, prefix, largest_ptr->prime_factors[0] ); 
      }
   }
   *largest_min_pf = largest_ptr->val;
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
