#include <stdio.h>
#include <ctype.h>

int isvowel(char a){
  char testchar=tolower(a);
  if(testchar=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
    return 1;
  }else{
    return 0;
  }
}

int main(void){

char inputChar;
scanf("%c", &inputChar);

int properties[7]={isalnum(inputChar),isupper(inputChar),islower(inputChar),
  isvowel(inputChar),isdigit(inputChar),isxdigit(inputChar),ispunct(inputChar)};
printf("The properties of '%c' can be represented by ", inputChar);
for(int i=0; i<7; i++){
  if (properties[i]>0){
    properties[i]=1;
  }
  printf("%d",properties[i]);
}
printf("\n");
  return 0;
}
