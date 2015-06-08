#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CONE_NUM 10

struct cone_coord {
  int x,y;
}Cones[CONE_NUM];


int test_cases = 0, radius_inner = 0, radius_outer = 0;
int cone_number = 0; 

void input_reader(void) {
  char buf[10], *tok = NULL;
  fgets(buf,10,stdin);
  tok = strtok(buf," ");
  if(!tok) {
    printf("Error: no test cases\n");
    return ;
  }
  test_cases = atoi(tok);
}

void main(void) {
}
