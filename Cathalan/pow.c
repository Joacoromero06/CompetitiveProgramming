#include <stdio.h>

typedef long long int ll;

ll pou(int a, int b) {
  if ( b==0 ) return 1;
  ll x = a, x_ant;
  for (int i = 2; i <= b; i++) {
    x_ant = x;
    for (int j = 1; j < a; j++) {
      x += x_ant;
    }
    //printf("%d ** %d = %lld\n", a, i, x);
    
  }
  return x;
}
ll multiply(int, int);
ll pouu(int a, int b){
  if (b) {
    if (b >= 1)
      printf("pow(%d, %d) = multiply(%d,\n\t\t ", a,b,a);
    ll m = multiply(a, pouu(a, b-1));
    if (b > 1) printf(")");
    return m;
  } 
  printf("pow(x, 0) = 1)");
  return 1;
}
ll multiply(int a, int b){
  if (a < b) return multiply(b, a);
  if (b) {
    //printf("multiply(%d, %d) = %d + ",a,b,a); 
    return a + multiply(a,b-1);
  }
  //printf("multiply(x,0) = 0\n");
  return 0;
}
int main() {
  printf("\ncall to pow. %lld\n", pouu(3,4));
  return 0;
}
  
