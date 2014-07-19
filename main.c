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

void left(int* array){
  static int can_left_flag = 0;
  static int counter = 0;
  while(counter<16){
    if ( *(array+counter) == *(array+1+counter) ){
      can_left_flag = 1;
    }
    ++counter;
  }
  printf("Can do left.\n");
}

void input(int* array){
  if ( getchar() == 'a' ) {
    left(array);
  };
}

void initprompt(){
  printf("1024 clone. Press\n"
	 "a for left\n"
	 "d for right\n"
	 "w for up\n"
	 "d for down\n"
	 "You also need to press the return key to input.\n");
}

int main(){

  int* box = malloc (sizeof(int) * ELEMENTS);
  initbox(box);

  initprompt();

  *(box+4) = 2;
  *(box+5) = 2;

  printbox(box);



  srand(time(NULL));
  int r = rand() % 16;
  
  
  input(box);


  free(box);
  return 0;




}
