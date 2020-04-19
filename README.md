# Largest Minimum Prime Factor

Practice C++ code for finding the value with largest minimum prime factor out of a set of values.

# Original Description
Many programming languages allow you to specify computations to be run in parallel. While Concurrent computing is focused on concurrency, the purpose of this task is to distribute time-consuming calculations on as many CPUs as possible.<br>

Assume we have a collection of numbers, and want to find the one with the largest minimal prime factor (that is, the one that contains relatively large factors). To speed up the search, the factorization should be done in parallel using separate threads or processes, to take advantage of multi-core CPUs.<br>

Show how this can be formulated in your language. Parallelize the factorization of those numbers, then search the returned list of numbers and factors for the largest minimal factor, and return that number and its prime factors.<br>

For the prime number decomposition you may use the solution of the Prime decomposition task.<br>
Prime Decomposition:<br>

(http://rosettacode.org/wiki/Prime\_decomposition)

The prime decomposition of a number is defined as a list of prime numbers which when all multiplied together, are equal to that number.<br>

Example<br>

 12 = 2 × 2 × 3,  so its prime decomposition is  {2, 2, 3}<br>


## Task

Write a function which returns an array or collection which contains the prime decomposition of a given number n greater than 1.<br>

If your language does not have an isPrime-like function available, you may assume that you have a function which determines whether a number is prime 
(note its name before your code).<br>

If you would like to test code from this task, you may use code from trial division or the Sieve of Eratosthenes.<br>

Note: The program must not be limited by the word size of your computer or some other artificial limit; it should work for any number regardless of size 
(ignoring the physical limits of RAM etc).<br>
