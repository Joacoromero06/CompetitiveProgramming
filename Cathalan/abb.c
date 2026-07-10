#include "abb.h"

n_abb* createAbb(n_abb* l, n_abb* r, int k){
  n_abb* a = malloc(sizeof(n_abb));
  if( a== NULL){
    perror("error malloc\n");
    exit(1);
  }
  a->l = l;
  a->r = r;
  a->x = k;
  a->c = 0;
  return a;
}
void deleteAbb(n_abb** p_a) {
  if (p_a == NULL) {
    printf("error: referencia de arbol nula\n");
    return;
  }
  if (*p_a == NULL) {
    return;
  }
  else {
    printf("freeing left tree:\n\t");
    deleteAbb(&((*p_a)->l));
    printf("freeing right tree:\n\t");
    deleteAbb(&((*p_a)->r));

    printf("freeing node tree\n");
    free(*(p_a));
  }
}
void meter(n_abb** p_a, int k){
  if (p_a == NULL) {
    printf("error: referencia a arbol nula");
    return;
  }
  if (*p_a == NULL) {
    *p_a = createAbb(NULL, NULL, k);
  }
  else if ( k == (*p_a)->x ) {
    (*p_a)->c++;
  }
  else if ( k < (*p_a)->x ) {
    meter( &((*p_a)->l), k);
  }
  else {
    meter( &((*p_a)->r), k);
  }
}
void preOrder(n_abb* a) {
  if ( a == NULL ) {
    printf("");
    return;
  }
  printf("%d", a->x);
  if ( a->l == NULL && a->r == NULL ) {

  }else if ( a->l == NULL ) {
    printf(" ~ ");
    preOrder(a->r);
  }else if (a->r == NULL ) {
    printf(" ¬ ");
    preOrder(a->l);
  }else {
    printf("(");
    preOrder(a->l);
    printf(",");
    preOrder(a->r);
    printf(")");
  } 
}
  
