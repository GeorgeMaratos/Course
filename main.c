#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CONE_NUM 10

struct cone_coord {
  int x,y;
}Cones[CONE_NUM];


int test_cases = 0, radius_inner = 0, radius_outer = 0;
int cone_number = 0; 

int input_reader(FILE *f) {
  char buf[10], *tok = NULL;
  int i = 0;
  fgets(buf,10,f);
  tok = strtok(buf," \n");
  if(!tok) {
    printf("Error: no test cases\n");
    return 1;
  }
  test_cases = atoi(tok);
  fgets(buf,10,f);
  tok = strtok(buf," ");
  if(!tok) {
    printf("Error: no boundary defined\n");
    return 1;
  }
  radius_inner = atoi(tok);
  tok = strtok(NULL," \n");
  if(!tok) {
    printf("Error: no boundary defined2\n");
    return 1;
  }
  radius_outer = atoi(tok);
  fgets(buf,10,f);
  tok = strtok(buf," \n");
  if(!tok) {
    printf("Error: no cone # defined\n");
    return 1;
  }
  cone_number = atoi(tok);
  for(i=0;i<cone_number;i++) {
    fgets(buf,10,f);
    tok = strtok(buf," \n");
    Cones[i].x = atoi(tok);
    tok = strtok(NULL," \n");
    Cones[i].y = atoi(tok);
  }
  return 0;
}

int main(int argc, char **argv) {
  if(argc != 2) {
    printf("Error: improper number of arguements\n");
    return 1;
  }
  FILE *f = NULL;
  f = fopen(argv[1],"r");
  return input_reader(f);
}
