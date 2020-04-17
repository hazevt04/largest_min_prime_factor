#ifndef __PF_H__
#define __PF_H__

#include "prime_decomposition.h"

typedef struct pf_s {
   int val;
   int num_prime_factors;
   // TODO: Size of the array is a guess. So far, the most
   // prime factors observed has been 4
   int prime_factors[10];
} pf_t;


void gen_pfs( pf_t* pfs, const int num_pfs );

void calc_pfs( pf_t* pfs, const int num_pfs, const bool debug );

void print_pf( const pf_t* pf, const char* prefix );

void print_pfs( const pf_t* pfs, const int num_pfs, const char* prefix );

#endif // end of #ifndef __PF_H__
