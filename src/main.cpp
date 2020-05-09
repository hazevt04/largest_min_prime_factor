// C++ File for main

#include <string.h>
#include "pf_thread.h"

void usage( const char* prog_name ) {
   printf( "Usage: %s <number of random values>\n", prog_name );
   printf( "\tReturns list of prime numbers which\n" );
   printf( "\twhen all multiplied together, are\n" );
   printf( "\tequal to that number.\n" ); 
}

int main( int argc, char** argv ) {
   int num_pfs = 8;
   bool debug = false;
   bool use_alt_imp = false;
   char* end_ptr = NULL;
   debug_printf( debug, "argc is %d\n", argc );
   if ( argc > 2 ) {
      debug_printf( debug, "argc > 1\n" ); 
      if ( !strcmp( argv[2], "--alt" ) ||
        ( !strcmp( argv[2], "-a" ) ) ) {
         use_alt_imp = true;
      } else {
         printf( "ERROR: Invalid input: %s\n", argv[2] ); 
         usage( argv[0] );
         exit( EXIT_FAILURE );
      }
   }
   if ( argc > 1 ) {
      debug_printf( debug, "argc > 0\n" ); 
      if ( !strcmp( argv[1], "--help" ) ||
        ( !strcmp( argv[1], "-h" ) ) ) {
         usage( argv[0] );
         exit( EXIT_SUCCESS );
      }
      num_pfs = strtol( argv[1], &end_ptr, 10 );
      if ( *end_ptr != '\0' ) {
         printf( "ERROR: Invalid input: %s\n", argv[1] ); 
         usage( argv[0] );
         exit( EXIT_FAILURE );
      }
   } // end of if ( argc > 1 )

   int num_threads = 8;
   int pfs_per_thread = CEILING( num_pfs, num_threads );
   debug_printf( debug, "Num PFs = %d\n", num_pfs ); 
   debug_printf( debug, "Num Threads = %d\n", num_threads ); 
   debug_printf( debug, "PFs Per Thread = %d\n", pfs_per_thread ); 
   debug_printf( debug, "Use Alternate Implementation = %s\n", ( use_alt_imp ? "true" : "false" ) ); 
   
   pthread_t threads[ num_threads ];
   pf_thread_args_t args[ num_threads ];
   srand(time(NULL));
   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      args[thread_num].thread_num = thread_num;
      args[thread_num].num_pfs = pfs_per_thread;
      args[thread_num].use_alt_imp = use_alt_imp;
      args[thread_num].pfs = (pf_t*)malloc( sizeof(pf_t) * pfs_per_thread );
      
      int max_val = 1000;
      for( int index = 0; index < pfs_per_thread; index++ ) {
         args[thread_num].pfs[ index ].val = ( rand() % max_val ) + 2; 
      } 
      args[thread_num].debug = debug;
   }

   Duration_ms duration_ms;
   Time_Point start_time = Steady_Clock::now();
   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {

      int t = pthread_create( &(threads[thread_num]), NULL, pf_thread, (void*)&(args[thread_num]) );
      if (t != 0) {
         printf( "Error in thread %d creation: %d\n", thread_num, t );
      }      
   }

   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      pthread_join( threads[ thread_num ], NULL );
   } 
   duration_ms = Steady_Clock::now() - start_time;

   int val_with_largest_min_pf = args[ 0 ].pfs[0].val;
   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      std::string thread_str = "Thread "; 
      thread_str += std::to_string( thread_num );
      thread_str += ": ";

      print_pfs( &(args[ thread_num ].pfs[0]), args[ thread_num ].num_pfs, thread_str.c_str() );
      
      printf( "%sValue with the largest minimum prime factor: %d\n\n", thread_str.c_str(), args[ thread_num ].largest_min_prime_factor );
      if ( args[ thread_num ].largest_min_prime_factor > val_with_largest_min_pf ) {
         val_with_largest_min_pf = args[ thread_num ].largest_min_prime_factor;
      }

      free( args[ thread_num ].pfs );
      args[ thread_num ].pfs = NULL;
   }
   printf( "Value with Largest Minimum Prime Factor was %d\n", val_with_largest_min_pf );
   printf( "Processing %d inputs took %8.7f ms\n", num_pfs, duration_ms.count() ); 
   exit( EXIT_SUCCESS );
}


