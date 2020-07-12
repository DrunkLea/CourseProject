#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FIELD 30

char *find_suffix(char *s1, char *s2)
{
  char *suffix = malloc(strlen(s1));
  int i = strlen(s1) - 1;
  int j = strlen(s2) - 1;

  for(;i >= 0 && j >= 0; i--, j--) {
    if(s1[i] == s2[j]) {
      strcpy(suffix, &s1[i]);
    }else
      return suffix;
  }

  return suffix;
}

int main(void)
{
  char str1[MAX_FIELD + 1];
  char str2[MAX_FIELD + 1];
  char *result;

  if(scanf("%s%s", str1, str2) == 2){
    result = find_suffix(str1, str2);
    printf("Common suffix between '%s' and '%s' is '%s'\n",
    str1, str2, result);
    free(result);
  }

  return 0;
}
