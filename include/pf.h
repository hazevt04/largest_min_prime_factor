#ifndef __PF_H__
#define __PF_H__

#include "utils.h"

typedef struct pf_s {
   int val;
   int num_prime_factors;
   // TODO: Size of the array is a guess. So far, the most
   // prime factors observed has been 4
   int prime_factors[10];
} pf_t;

inline bool divides( int num, int div ) {
   return ( ( num != 0 ) && ( ( num % div ) == 0 ) );
}

void copy_pf( pf_t* dest, const pf_t* src );

void num_primes_up_to_val( int* num_primes, const int val, const bool debug );

void calc_pf( pf_t* pf, const bool debug, const char* __restrict__ prefix );

void print_pf( const pf_t* __restrict__ pf, const char* __restrict__ prefix );


void init_pfs( pf_t* pfs, const int* __restrict__ vals, const int num_vals );

void gen_pfs( pf_t* pfs, const int num_pfs );

void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug, const char* __restrict__ prefix );

void print_pfs( const pf_t* __restrict__ pfs, const int num_pfs, const char* __restrict__ prefix );


#endif // end of #ifndef __PF_H__
