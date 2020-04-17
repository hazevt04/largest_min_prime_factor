#ifndef __PRIME_DECOMPOSITION_H__
#define __PRIME_DECOMPOSITION_H__

#include <math.h>
#include "sieve.h"

inline bool divides( int num, int div ) {
   return ( ( num != 0 ) && ( ( num % div ) == 0 ) );
}

void prime_decomposition( int* __restrict__ prime_factors, int* __restrict__ num_prime_factors, const int val, const bool debug );

#endif // end of #ifndef __PRIME_DECOMPOSITION_H__
