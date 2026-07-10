#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ABB{
  int x;
  int c;
  struct ABB* l;
  struct ABB* r;
} n_abb;
//typedef n_abb* abb;
n_abb* createAbb(n_abb* l, n_abb* r, int);
void deleteAbb(n_abb** p_a);
void meter(n_abb** p_a, int);
void eliminar(n_abb** p_a, int);
void find(n_abb* a, int k, int* refB, n_abb** K);
void preOrder(n_abb* a);

