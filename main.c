#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define CONE_NUM 10
#define SCORE_NUM 10
#define INT_MAX  10000000000.0

struct cone_coord {
  int x,y;
  double closest_boundary;
}Cones[CONE_NUM];


int test_cases = 0, radius_inner = 0, radius_outer = 0;
int cone_number = 0; 
float scores[SCORE_NUM] = {0.0};

void find_max(void) {
  int i;
  double temp_rad = 0.0, inner_boundary = 0.0, outer_boundary = 0.0;
  for(i=0;i<CONE_NUM;i++) {
    temp_rad = sqrt((double)(Cones[i].x*Cones[i].x + Cones[i].y*Cones[i].y));
    inner_boundary = temp_rad - radius_inner;
    outer_boundary = radius_outer - temp_rad;
    if(inner_boundary > 0.0 && outer_boundary > 0.0) {
      if(inner_boundary > outer_boundary)
        scores[i] = inner_boundary;
      else scores[i] = outer_boundary;
    }
    else {
      scores[i] = 0.0;
    }
  }
}
      
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
  find_max();
  return 0;
}

int main(int argc, char **argv) {
  int i;
  double result = INT_MAX;
  if(argc != 2) {
    printf("Error: improper number of arguements\n");
    return 1;
  }
  FILE *f = NULL;
  f = fopen(argv[1],"r");
  if(input_reader(f)) {
    printf("Error: file format not correct\n");
    return 1;
  }
  printf("output----\n");
  for(i=0;i<CONE_NUM;i++) {
    if(scores[i] != 0 && scores[i] < result)
      result = scores[i];
  }
  printf("%f\n",result);
}
