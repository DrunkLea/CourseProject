#include <stdio.h>

char grids[9];

void init_grid(void){
  for (int i=0;i<9;i++){
    grids[i]=' ';
  }
}
void display_grid(void){
  int k=0;
  for(int i=0;i<3;i++){
    printf("-------\n|");
    for(int j=0;j<3;j++){
      printf("%c|",grids[k]);
      k++;
    }
    printf("\n");
  }
  printf("-------\n");
}

int play(char player,int pos){
  if(grids[pos]!=' '){
    return 0;
  }else{
    grids[pos]=player;
  }
  return 1;
}

int is_horizontal_winner(char player){
    for (int i=0;i<7;i+=3){
      int token=0;
      for(int j=0;j<3;j+=1){
        if (grids[i+j]==player)
          token++;
        if (token==3)
          return 1;
    }
  }
  return 0;
}
int is_vertical_winner(char player){
  for (int i=0;i<3;i++){
    int token=0;
    for(int j=0;j<7;j+=3){
      if (grids[i+j]==player)
        token++;
      if (token==3)
        return 1;
    }
  }
  return 0;
}
int is_diag_winner(char player){
  int token=0;
  for (int i=0;i<9;i+=4){
    if (grids[i]==player){
      token++;
    }
    if(token==3){
      return 1;
    }
  }
  token=0;
  for (int i=2;i<7;i+=2){
    if (grids[i]==player)
      token++;
    if(token==3)
      return 1;
  }
  return 0;
}

int is_win(char player){
  if(is_horizontal_winner(player)+is_vertical_winner(player)+is_diag_winner(player)>0){
    return 1;
  }
  return 0;
}
int is_tie(void){
  for(int i=0; i<9;i++){
    if (grids[i]==' '){
      return 0;
    }
  }
  return 1;
}


int main(void){
  init_grid();
  display_grid();

  int pos;
  int current_player;
  char current_mark;
  int rounds_track=1;

  while(1){
      if(rounds_track%2!=0){
        current_player=1;
        current_mark='X';
      }else{
        current_player=2;
        current_mark='O';
      }

    printf("Enter cell for Player %d\n",current_player);
    scanf("%d", &pos);

      if(pos>8||pos<0){
        printf("Invalid cell\n");
        continue;
      }else{
        if (!play(current_mark,pos)){
          printf("Cell already occupied\n");
          continue;
        }
      }

    display_grid();

    if (is_win(current_mark)){
      printf("Player %d wins!\n",current_player);
      break;
    }

    if (is_tie()){
      break;
    }
    rounds_track++;
  }

  return 0;
}
