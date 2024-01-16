#include <stdio.h>
#include <stdint.h>

#define MAX 49
#define RANGE (MAX-1)

uint32_t secret[49] = {0};

void Push(int y, int x, char val);

void Push(int y, int x, char val){
  if(val=='*'){
    val = 1;
  }else{
    val = 0;
  }
  secret[y] = secret[y]&~(1<<(31-x));
  secret[y] ^= (val<<(31-x));
}

int main(){
  char a[MAX][32] = {
    {'*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' '},
    {'*', '*', '*', ' ', ' ', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' '},
    {'*', ' ', '*', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', '*', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' '},
    {' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', '*', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' '},
    {' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', '*', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' '},
    {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' '},
    {' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', ' ', '*', '*'},
    {'*', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' '},
    {'*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', ' ', '*', ' ', ' '},
    {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' '},
    {' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
  };

  for (int i = 0; i < MAX; i++)
    for(int j = 0; j < 32; j++){
      Push(i,j,a[i][j]);
    }
  
  printf("{");
  for(int k=0; k<MAX; k++){
    if (k==RANGE){
      printf("%u\n", secret[k]);
      break;
    }
    printf("%u,\n", secret[k]);
  }
  printf("}");

  return 0;
}