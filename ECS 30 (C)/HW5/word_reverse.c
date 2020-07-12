#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD 80

int to_next_word(int current_ptr, char *line)
{
   for (int i = current_ptr; i < strlen(line); i++) {
     if(line[i] == '\n'){
       line[i] = 0;
       return i;
     }else if(line[i] != ' ')
       continue;
      else
        return i;
  }
   return -1;
}

int word_count(char *line)
{
  int count = 1;
  for (int i = 0; i < strlen(line); i++) {
    if(line[i] == ' ')
      count++;
  }
  return count;
}

int word_len(int current_ptr, char *line)
{
  return to_next_word(current_ptr, line) - current_ptr;
}

char **tokenize_words(char *line)
{
  int count = word_count(line);
  int current_ptr = 0;

  char **words =  malloc(count * sizeof(char*));
  for (int i = count-1; i >= 0; i--) {
    int len = word_len(current_ptr, line);
    words[i] = malloc(len);
    strncpy(words[i], &line[current_ptr], len);
    words[i][len] = 0;
    current_ptr += len + 1;
  }

  return words;
}


int main(void)
{
  char str[MAX_FIELD];
  char **rev_words;
  char *rev = malloc(strlen(str));
  int words;

  fgets(str, MAX_FIELD, stdin);

  rev_words = tokenize_words(str);
  words = word_count(str);
  for (int i = 0; i < words; i++) {
    strcat(rev, rev_words[i]);
      if (i != words - 1)
        strcat(rev, " ");

    free(rev_words[i]);
  }
  rev[strlen(str)] = 0;
  printf("Input: %s\nOutput: %s\n", str, rev);

  free(rev_words);
  free(rev);

  return 0;
}
