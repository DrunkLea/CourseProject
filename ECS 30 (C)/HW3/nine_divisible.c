#include <stdio.h>

int main(void){
  int inputNum;
  int sum=0;
  scanf("%d", &inputNum);

  if(inputNum<=0){
    printf("Invalid value\n");
    return 1;
  }

  for(double i=inputNum;i>=1;i*=0.1){
   printf("currentNum is %lf\n",i);
    printf("%d\n",(int)i%10);
    sum+=(int)i%10;
  }
  if(sum%9==0){
    printf("Number %d is divisible by 9\n", inputNum);
  }else{
    printf("Number %d is not divisible by 9\n", inputNum);
  }

  return 0;
}
