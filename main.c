#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ELEMENTS 16

void initbox(int* array){
  static int counter;
  counter = 0;
  while(counter<ELEMENTS){
    *(array+counter) = 0;
    ++counter;
  }
}

void printbox(int* array){
  static int counter;
  counter = 0;
  while(counter<ELEMENTS){
    printf("\033[34m%d\033[0m   ",*(array+counter));
    ++counter;
    if(counter != 16 && counter % 4 == 0){
      printf("\n\n\n");
    }
    if(counter == 16){
      printf("\n");
    }
  }
}


int main(){

  int* box = malloc (sizeof(int) * ELEMENTS);
  initbox(box);


  *(box+2) = 2;
  *(box+4) = 6;

  printbox(box);

  srand(time(NULL));
  int r = rand() % 16;






  free(box);
  return 0;




}
