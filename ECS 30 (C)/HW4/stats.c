#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_SIZE 20

double numbers[MAX_SIZE];
int count;
double max, min, avg, stdev;

void get_stats(double numbers[],int count,double *max,double *min,double *avg, double *stdev){
  *min=numbers[0];
  *max=numbers[0];
  double sum=0;
  double sqrt_sum=0;

  for(int i=0;i<count;i++){
    sum+=numbers[i];
    sqrt_sum+=powf(numbers[i],2);
    if(numbers[i]<*min)
      *min=numbers[i];
    if(numbers[i]>*max)
      *max=numbers[i];
  }

  *avg=sum/count;
  *stdev=sqrt((sqrt_sum/count)-(*avg * *avg));
}

int main(void){

  scanf("%d",&count);
  if (count>0&&count<MAX_SIZE){
    for(int i=0;i<count;i++){
      if (scanf("%lf", &numbers[i])!=1){
        printf("Invalid input\n");
        return 1;
      }
    }
    get_stats(numbers,count,&max,&min,&avg,&stdev);

    printf("Min: %.2lf\nMax: %.2lf\nAvg: %.2lf\nStd: %.2lf\n",min,max,avg,stdev);

    return 0;
  }else{
      printf("Invalid size\n" );
      return 1;
  }

}
