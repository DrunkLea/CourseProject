#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

int get_player_move(void){
  char player_move;
  int num=3;

  while(1){
    printf("[Rr]ock, [Pp]aper or [Ss]cissors? (or [Qq]uit)\n");
    scanf(" %c", &player_move);

    switch (player_move) {
      case 'r':
      case 'R':
            num=ROCK;
            break;
      case 'p':
      case 'P':
            num=PAPER;
            break;
      case 's':
      case 'S':
            num=SCISSORS;
            break;
      case 'q':
      case 'Q':
            num=-1;
            break;
      }
      if(num==3){
        printf("Invalid move, try again!\n");
        continue;
      }else{
        return num;
      }
    }
}

int get_cpu_move(void){
  int cpu_move=rand()%3;
  return cpu_move;
}

char *num_to_word(int num){
  char *move;
  switch (num) {
    case 0:
      move="Rock";
      break;
    case 1:
      move="Paper";
      break;
    case 2:
      move="Scissors";
      break;
  }
  return move;
}
void print_winner(int player_move, int cpu_move){
  char *player=num_to_word(player_move);
  char *cpu=num_to_word(cpu_move);
  char *result;

  int rst=player_move - cpu_move;
  switch (rst) {
    case 2:
    case -1:
      result="You lose!";
      break;
    case 1:
    case -2:
      result="You win!";
      break;
    default:
      result="Tie!";
      break;
  }
  printf("%s versus %s... %s\n",player,cpu,result);
}

int main(void){
  int player_move,cpu_move;
  srand(time(0));
  while(1){

    player_move=get_player_move();
    if(player_move==-1){
      break;
    }
    cpu_move=get_cpu_move();
    print_winner(player_move,cpu_move);
  }

  return 0;
}
