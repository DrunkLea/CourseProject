#include <stdio.h>

int main(void){
  float trueBearing;
  scanf("%f", &trueBearing);

if(trueBearing<0||trueBearing>360){
  printf("Ivalid compass heading\n");
  return 1;
}

  switch ((int)trueBearing/90){
    case 0:
      printf("North %.1f East\n", trueBearing);
      break;
    case 1:
      printf("South %.1f East\n", 180-trueBearing);
      break;
    case 2:
      printf("South %.1f West\n", trueBearing-180);
      break;
    case 3:
      printf("North %.1f West \n", 360-trueBearing);
      break;
  }

  return 0;
}
