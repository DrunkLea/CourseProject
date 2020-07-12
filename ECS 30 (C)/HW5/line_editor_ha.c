#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 80

void remove_newline(char *str)
{
  int len = strlen(str)
  if (str[len - 1] == '\n')
    str[len - 1] = 0;
}

void empty_input_buffer()
{
  while(1) {
    if (getchar() == '\n')
    break;
  }
}

char command(void)
{
  char command;
  printf("Enter [Dd] (delete), [Ii] (insert), or [Qq] (quit): \n");
  //get char
  return tolower(command);
}

int locate(char *substring)
{

}

void delete(int position, int count, char *string)
{
  printf("Enter string to delete:\n");

  printf("Source string is: '%s'\n", *string);
}

void insert(char *string)
{
  char *substring;
  int position;

  printf("Enter string to insert:\n");

  printf("Enter position to insert:\n");

  printf("Source string is: '%s'\n", *string);
}
*/
int main(void)
{
  char string[MAX_LINE];

  printf("Enter the source string:\n");
  fgets(string, MAX_LINE, stdin);
  remove_newline(string);
  printf("Source string is: '%s'\n", string);

  switch (command()) {
    case 'd':
      delete();
      break;
    /*case 'i':
      insert();
      break;
    case 'q':
      printf("Final string: '%s'\n", string);
      break;
    default:
      printf("Invalid command\n");
      break;
  }*/

  return 0;
}
