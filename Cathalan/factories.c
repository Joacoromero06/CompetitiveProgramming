#include "factories.h"
#include "pow.c"

void createSkewed(){
  n_abb* a = NULL;
  for (int i = 0; i < 4; i ++){
    meter(&a, i);
  }
  preOrder(a);
  printf("\n");
}
void createDegenerated(){
  n_abb* a = NULL;
  int n = 6;
  for ( int i = 1; i<=n/2; i++ ) {
    meter(&a, i);
    meter(&a, n-(i-1));
  }
  
  preOrder(a);
  printf("\n");
}
static int log_2(int n) {
  int c = 0;
  while (n > 1) {
    n/=2;
    c ++ ;
  }
  return c;
}
void addMiddle(n_abb** p_a, int ini, int fin) {
  if (p_a == NULL) {
    printf("error: referencia nula");
    return;
  }
  if ( ini > fin ) {
    // caso base fin
    return;
  } else if (*p_a != NULL) {
    // codigo para agregar middle values en arbol no vacio
  } else if (ini == fin) {
    meter(p_a, ini);
  } else {
    int med = (fin - ini + 1) / 2;
    meter(p_a, med);
    addMiddle( &((*p_a)->l), ini, med-1);
    addMiddle( &((*p_a)->r), med+1, fin);
  }
}

void createPerfect() {
  n_abb* a = NULL;
  int n = 8, incremento;
  for ( int l = 0; l <= log_2(n)-1; l++ ) {
    incremento = n / pou(2,l+1);
    for ( int i = 0; i <= pou(2,l)-1; i++ ) {
      printf("l = %d | i = %d | r = %d | p = %d | e = %d\n", l, i, (2*i + 1), incremento, incremento * (2*i + 1));
      meter(&a, incremento * (2*i+1));
    }
  }
  preOrder(a);
  printf("\n");
}
void createPerfectRange(int ini, int fin) {
  n_abb * a = NULL;
  addMiddle(&a, ini, fin);
  preOrder(a);
  printf("\n");
}
