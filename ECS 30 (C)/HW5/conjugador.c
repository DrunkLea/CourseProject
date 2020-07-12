#include <stdio.h>
#include <string.h>

#define MAX_VERB 30
#define CONJUGATE_TIMES 5
#define SUFFIX_FIELD 2

int valid_test(char *word)
{
  char suffix[SUFFIX_FIELD + 1];
  int suffix_start = strlen(word) - SUFFIX_FIELD;

  strncpy(suffix, word + suffix_start, SUFFIX_FIELD);
  suffix[SUFFIX_FIELD] = 0;
  if(strcmp("ar", suffix) != 0){
    printf("Not a correct -ar verb\n");

    return 1;
  }

  return 0;
}

void conjugate(char *pronouns[], char *endings[], char *word)
{
  word[strlen(word) - SUFFIX_FIELD] = 0;
  for(int i = 0; i < CONJUGATE_TIMES; i++) {
    printf("%s %s%s\n", pronouns[i], word, endings[i]);
  }
}

int main(void)
{
  char word[MAX_VERB + 1];
  char boolean = '\0';
  char *pronouns[CONJUGATE_TIMES] = {"yo", "tu",
   "usted", "nosotros", "ustedes"};
  char *endings[CONJUGATE_TIMES] = {"o", "as", "a", "amos", "an"};

  do {
    printf("Enter a spanish verb (-ar):\n");
    scanf("%s", word);
    if(!valid_test(word))
      conjugate(pronouns, endings, word);
    printf("Conjugate another verb? [Yy]\n");
    scanf(" %c", &boolean);
  } while(boolean == 'Y' || boolean == 'y');

  return 0;
}
