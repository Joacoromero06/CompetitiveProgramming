#include <stdio.h>

// Given an integer convert all digits 0 to 5
int ceroToFive(int n, int k, int r){
  if (n==0)
    return 0;
  int d = n % 10;
  if (d == k)
    d = r;
  return ceroToFive( (int)n/10, k, r ) * 10 + d;
}
int main() {
  int n = 332123133;
  printf("%d -> %d\n", n, ceroToFive(n, 3, 5));
  return 0;
}
