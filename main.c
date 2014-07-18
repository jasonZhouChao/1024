#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEMENTS 16

int main(){

  int* box = malloc (sizeof(int) * ELEMENTS);

  srand(time(NULL));
  int r = rand() % 16;
  printf("%d\n",r);

  free(box);
  return 0;
}
