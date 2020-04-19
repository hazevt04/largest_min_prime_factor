// C++ File for main

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
   char* end_ptr = NULL;
   if ( argc > 1 ) {
      num_pfs = strtol( argv[1], &end_ptr, 10 );
      if ( *end_ptr != '\0' ) {
         printf( "ERROR: Invalid input: %s\n", argv[1] ); 
         usage( argv[0] );
         exit( EXIT_FAILURE );
      }
   } // end of if ( argc > 1 )

   pf_t val_with_largest_min_pf;

   int num_threads = 8;
   int pfs_per_thread = CEILING( num_pfs, num_threads );
   debug_printf( debug, "Num PFs = %d\n", num_pfs ); 
   debug_printf( debug, "Num Threads = %d\n", num_threads ); 
   debug_printf( debug, "PFs Per Thread = %d\n", pfs_per_thread ); 
   
   pthread_t threads[ num_threads ];
   pf_thread_args_t args[ num_threads ];

   srand(time(NULL));
   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      args[thread_num].thread_num = thread_num;
      args[thread_num].num_pfs = pfs_per_thread;
      args[thread_num].pfs = (pf_t*)malloc( sizeof(pf_t) * pfs_per_thread );
      
      int max_val = 1000;
      for( int index = 0; index < pfs_per_thread; index++ ) {
         args[thread_num].pfs[ index ].val = ( rand() % max_val ) + 2; 
      } 
      args[thread_num].debug = debug;

      int t = pthread_create( &(threads[thread_num]), NULL, pf_thread, (void*)&(args[thread_num]) );
      if (t != 0) {
         printf( "Error in thread %d creation: %d\n", thread_num, t );
      }      
   } 

   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      pthread_join( threads[ thread_num ], NULL );
   } 

   for( int thread_num = 0; thread_num < num_threads; thread_num++ ) {
      std::string thread_str = "Thread "; 
      thread_str += std::to_string( thread_num );
      thread_str += ": ";

      print_pfs( &(args[ thread_num ].pfs[0]), args[ thread_num ].num_pfs, thread_str.c_str() );
      
      free( args[ thread_num ].pfs );
      args[ thread_num ].pfs = NULL;
   }
   exit( EXIT_SUCCESS );
}


