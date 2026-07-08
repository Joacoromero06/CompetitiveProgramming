#include <stdio.h>

typedef long long int ll;

ll nBST(int N) {
  if ( N <= 1 ) return 1;
  ll n = 0;
  for (int k = 0; k <= N-1; k++){ // k node choosen as root
    n += nBST(k) * nBST(N-k-1);
  }
  return n;
}
ll nBSTdp(int N){
  ll cathalan[N+1];
  cathalan[0] = cathalan[1] = 1;
  
  for (int n = 2; n<= N; n++) {
    cathalan[n] = 0;
    for (int k = 0; k<n; k++) { 
      cathalan[n] += cathalan[k] * cathalan[n-k-1];
    }
  }
  return cathalan[N];
}

ll nBSTdp2(int N){
  int limite;
  ll dp[N+1];
  dp[0] = dp[1] = 1;
  for (int n = 2; n<=N; n++){
    dp[n] = 0;
    limite = (int) (n-1)/2;
    for (int k = 0; k <= limite; k++) {
      if (n&1 && k == limite)
        dp[n] += dp[k] * dp[n-k-1];
      else
        dp[n] += dp[k] * dp[n-k-1] * 2;
    }
  }
  return dp[N];
}
int main() {
  for (int i = 0; i <= 7; i++) {
    printf ("number of binary search trees = %lld, with V = {0..%d-1}\n",nBSTdp2(i), i);
  }
  return 0;
}
