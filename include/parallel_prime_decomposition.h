#ifndef __PARALLEL_PRIME_DECOMPOSITION_H__
#define __PARALLEL_PRIME_DECOMPOSITION_H__

#include "prime_decomposition.h"

#include "pf.h"

void parallel_prime_decomposition( pf_t* largest, const int* vals, const int num_vals, const bool debug );

#endif // end of #ifndef __PARALLEL_PRIME_DECOMPOSITION_H__
