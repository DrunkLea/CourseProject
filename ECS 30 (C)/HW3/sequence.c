#include <stdio.h>

int main(void){
  int startNum,step,endNum;
  scanf("%d %d %d",&startNum,&step,&endNum);
  if(endNum<startNum||step<=0){
    printf("Invalid values\n");
    return 1;
  }
  for (int i = startNum; i <= endNum; i+=step) {
    printf("%d ",i );
  }
  printf("\n");
  return 0;
}
