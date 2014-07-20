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
      printf("\n\n");
    }
    if(counter == 16){
      printf("\n\n");
    }
  }
}

void left(int* array){
  static int can_left_flag = 0;
  static int counter = 0;
  while(counter<16){
    if ( *(array+counter) != 0 &&
	 *(array+counter) == *(array-1+counter) ){
      can_left_flag = 1;
    }
    ++counter;
  }
  if ( can_left_flag == 1){
    printf("Can do left.\n");
  }
}

void right(int* array){
  static int can_right_flag = 0;
  static int counter = 0;
  while(counter<16){
    if ( *(array+counter) != 0 &&
	 *(array+counter) == *(array+1+counter) ){
      can_right_flag = 1;
    }
    ++counter;
  }
  if ( can_right_flag == 1){
    printf("Can do right.\n");
  }
}



void up(int* array){
  static int can_up_flag = 0;
  static int counter = 0;
  while(counter<16){
    if ( *(array+counter) != 0 &&
	 *(array+counter) == *(array-4+counter) ){
      can_up_flag = 1;
    }
    ++counter;
  }
  if ( can_up_flag == 1){
    printf("Can do up.\n");
  }
}


void down(int* array){
  static int can_down_flag = 0;
  static int counter = 0;
  while(counter<16){
    if ( *(array+counter) != 0 &&
	 *(array+counter) == *(array+4+counter) ){
      can_down_flag = 1;
    }
    ++counter;
  }
  if ( can_down_flag == 1){
    printf("Can do down.\n");
  }
}


void input(int* array){
  static char c;
  c = getchar();
  if ( c == 'a' ) {
    left(array);
  };
  if ( c == 'd' ) {
    right(array);
  };
  if ( c == 'w' ) {
    up(array);
  };
  if ( c == 's' ) {
    down(array);
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

void random2(int* array){

      srand(time(NULL));
      int r = rand() % 16;

      if ( *(array+r) == 0 ) {
          *(array+r) = 2;
      }

}

int main(){

  int* box = malloc (sizeof(int) * ELEMENTS);
  initbox(box);

  initprompt();

  printbox(box);


  random2(box);
  printbox(box);

  input(box);


  free(box);
  return 0;




}
