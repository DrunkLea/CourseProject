#include <stdio.h>
#include <stlib.h>

int add_sum(int count, int *items, int item_num){
  int sum = 0;

  for(int i = 0; i<count-1; i++){
    for(int j = 0; j<citem_num; j++){
    sum = i
  }
  return sum;
}

int sub_sum(int count, int *items, int item_num){
  for (int i = 0; i < count; i++) {
    n-count+item_num;
  }
}

int main(void)
{
  double *items_price;
  int count;
  int change_point = count / 2;
  int bill_amount;

  printf("Disclaimer: this program omits the situations when only 1 item is counted.\n"
    "Enter number of items in the list:\n");
  scanf("%d", &count);
  items_price = malloc(count * sizeof(double));
  printf("Enter bill amount:\n");
  scanf("%d", &bill_amount);

  for (int i = 0; i < count; i++) {
    printf("Enter price for item [%d].\n", i);
    scanf("%lf", items_price[i]);
    printf("Item[%d] price recorded.\n", i);
  }

  for(int i = 0; i < count; i++){ //< or <= ??
    if(i<change_point)
      add_sum(count, items_price, i);
    else
      sub_sum(count, items_price, i);
  }

  return 0;
}

//printf("Sorry, no solution.");
//printf("Item with price");
//printf(int[]);
//printf("should be in one purchase.");
