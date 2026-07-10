#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int* a, int* b) {
  int x = *a;
  *a = *b;
  *b = x;
}
void shuffle( int* arr, int n ) {
  int i_rand;
  for ( int i = n-1; i > 0; i-- ) {
    i_rand = rand() % (i+1); // the last element in the lefting array is also 
                             // probable to be choosen to goes to it same position
    swap(& (*(arr+i)), arr+i_rand);
  }
}
void printIntArr( int* arr, int n ) {
  printf("{");
  for (int i = 0; i < n; i++){
    ( i != n-1 ) ? printf("%d, ", arr[i]) : printf("%d", arr[i]);
  }
  printf("}");
}
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  srand (time(NULL));
  shuffle(arr, n);
  printIntArr(arr,n);
}



