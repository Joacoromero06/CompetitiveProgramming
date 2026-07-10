#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>

bool* createCriba(int n) {
  bool* primes = malloc(sizeof(bool) * n);
  if ( primes==NULL ) {
    perror("error malloc\n");
    return NULL;
  }
  memset( (void*) primes, false, n );
  for (int i = 2; i <= sqrt(n); i++) {
    :w
    for (int p = 2*i; p<=n; p+=i) {
      primes[p]=false;

