#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>


struct criba {
  bool* primes;
  int n;
};
struct criba createCriba(int n) {
  bool* primes = malloc(sizeof(bool) * n);
  if ( primes==NULL ) {
    perror("error malloc\n");
    return (struct criba){.primes = NULL, .n = -1};
  }
  memset( (void*) primes, true, n );
  for (int p = 2; p <= sqrt((float)n); p++) { // primo
    if ( primes[p] == false )
      break;
    for (int m = 2*p; m<=n; m+=p) { // multiplos
      primes[m]=false;
    }
  }
  return (struct criba){.primes = primes, .n = n};
}
void showCriba(struct criba c) {
  if ( c.primes == NULL ) {
    printf("error, criba vacia");
    return ;
  }
  int j = 0;
  for ( int i = 0; i < c.n; i++ ) {
    if ( c.primes[i] ) {
      if ( (++j) % 4 == 0 )
        printf("%d\n", i);
      else 
        printf("%d - ", i);
    }
  }
  printf("\n");
}

int main() {
  struct criba c = createCriba(1000);
  showCriba(c);
  return 0;
}
