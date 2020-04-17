// C++ File for prime_decomposition

#include <iostream>
#include <stdlib.h>

#include "prime_decomposition.h"

// bool divides( int num, int div );

bool is_prime( int val ) {
   int sqrt_val = sqrt(val);
   for( int index = 2; index <= sqrt_val; index++ ) {
      if ( divides( val, index ) ) {
         return false;
      }
   }
   return true;
}

void prime_decomposition( int* __restrict__ prime_factors, int* __restrict__ num_prime_factors, const int val, const bool debug=false ) {
   int t_primes[val+1];
   int num_t_primes = 0;

   sieve( &(t_primes[0]), &num_t_primes, val, debug );
   debug_printf( debug, "Number of primes up to %d is %d\n", val, num_t_primes ); 

   int t_val = val;
   int p_index = 0;
   int pf_index = 0;
   while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {
      if ( divides( t_val, t_primes[ p_index ] ) ) {
         debug_printf( debug, "%s(): Temp Val is %d\n", __func__, t_val ); 
         debug_printf( debug, "%s(): Temp Primes[ %d ] is %d\n", __func__, p_index, t_primes[ p_index ] );
         debug_printf( debug, "%s(): Temp Val was divisible by that prime. It is a prime factor\n\n", __func__ ); 
         prime_factors[ pf_index ] = t_primes[ p_index ];
         t_val = t_val/t_primes[ p_index ];
         pf_index++;
      } else {
         debug_printf( debug, "%s(): Temp Val is not divisible by that prime. Prime index incremented.\n\n", __func__ ); 
         p_index++;
      }
   } // end of while( ( p_index < num_t_primes ) && ( t_val > 1 ) ) {

   *num_prime_factors = pf_index;
}


// end of C++ file for prime_decomposition
