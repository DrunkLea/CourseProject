#include <stdio.h>

int main (void){
  float x,y;
  int quadrant=0;
  scanf("%f %f", &x, &y);
  printf("(%+.1f, %+.1f)",x,y);

  if (x==0&&y==0){
    printf(" is the origin\n");
  }else if (x==0){
    printf(" is on the y-axis\n");
  }else if(y==0){
    printf(" is on the x-axis\n");
  }else{
    if (x>0){
      if(y>0){
        quadrant=1;
      }else{
        quadrant=4;
      }
    }
    else if(x<0){
      if(y>0){
        quadrant=2;
      }else{
        quadrant=3;
      }
    }
    printf(" is in quadrant %d\n",quadrant);
  }
  return 0;
}
