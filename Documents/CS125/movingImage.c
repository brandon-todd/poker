/*There are 4 functions. print_array takes one input argument of a 
multidimentional array and does not return anything. clearScreen takes no
input arguments and does not return anythin. changeColor takes one integer 
input and does not return anything. The last function is main which takes no 
input and returns a 0.
*/
#include<stdio.h>
#include<unistd.h>

#define ROWS 10
#define COLS 20

void print_array(char lines[ROWS][COLS]){

  int x;
  for (x=0; x< ROWS; x++){
    printf("%s\n", lines[x]);
  }

}

void clearScreen(){
  sleep(1);
  printf("\e[2J\e[H");
}

void changeColor(int color){
  if(color==1){
    printf(" \e[1;31m");  //bold red font
  }
  else if(color==2){
    printf(" \e[1;34m");  //bold blue font
  }
  else if(color==3){
    printf(" \e[1;32m");  //bold green font
  }
  else{
    printf("\e[0m\n");
  }
}


int main(){

  char intro[ROWS][COLS]={ 
    "***************",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "*             *",
    "***************"};
  int y,new_row; 
  
  clearScreen();
  print_array(intro);
  for(y=1; y< (ROWS-1); y++){   
    new_row = ROWS-y;
    clearScreen();
    intro[y][y]='x';
    intro[new_row-1][y] = 'O';
    print_array(intro); 
    changeColor((y%3)+1);   
  } 

  changeColor(4);

  return 0;
}


