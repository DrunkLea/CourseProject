#include <stdio.h>
#include <string.h>

#define MAX_LINE_FIELD 80



int main(int argc,char argv[])
{
  char censored_words[argc - 1][];

  for(int i = 0;i < argc - 1;i++){
    strcpy(censored_words[i],argv[i])
  }


}
