#include <stdio.h>
typedef long long int ll;

ll factorial(int x){
  ll factorial = 1;
  for (int i = 1; i <= x; i ++) {
    factorial *= i;
  }
  return factorial;
}
ll C(int n, int k) {
  ll acum = 1;
  for ( int i = 1; i <= k; i++ ){
    acum *= (n-(i-1));
    acum /= i;
  }
  return acum;
}
ll cathalan(int n){
  return factorial(2*n) / (factorial(n+1) * factorial(n));
}
ll cathalan2(int n){
  return C(2*n, n) / (n+1);
}
int main (){
  for (int i = 0; i <= 7; i++) {
    printf("7C%d = %lld\n", i, C(7,i));
  }
  return 0;
}
