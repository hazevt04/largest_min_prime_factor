cmake_minimum_required( VERSION 2.8.0 )

project( largest_min_prime_factor )

find_package( GMP REQUIRED )

include_directories( 
   "${CMAKE_SOURCE_DIR}/include" 
   "${GMP_INCLUDES}" )

add_definitions( -std=c++11 )

set(EXEC_NAME "${CMAKE_PROJECT_NAME}")

set(SRCS
   "src/utils.cpp"
   "src/pf.cpp"
   "src/pf_thread.cpp"
   "src/main.cpp"
   )

add_executable( "${EXEC_NAME}" "${SRCS}" )
target_link_libraries( "${EXEC_NAME}" "${GMP_LIBRARIES}" m pthread )


