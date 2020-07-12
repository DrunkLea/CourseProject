#include <stdio.h>

int main(void){
  char (colorInput);
  scanf("%c", &colorInput);
  switch (colorInput) {
    case 'B':
    case 'b':
      printf("Carbon monoxide\n");
      break;
    case'O':
    case'o':
      printf("Ammonia\n");
      break;
    case'Y':
    case'y':
      printf("Hydrogen\n");
      break;
    case'G':
    case'g':
      printf("Oxygen\n");
      break;
    default:
      printf("Contents unknown\n");
      return 1;
  }
  return 0;
}
