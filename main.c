#include <stdio.h>

char board[3][3], names[2][30];

void print_board() {
  int i, j;
  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      fputc(board[i][j], stdout);
    }
    fputc('\n', stdout);
  }
}

int win(char board[3][3]) {
  if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] == board[0][2] && board[0][0] != '-') {
    return board[0][0] == 'X' ? 1 : 2;
  } else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] == board[2][2] && board[2][0] != '-') {
    return board[2][0] == 'X' ? 1 : 2;
  } else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] == board[1][2] && board[1][0] != '-') {
    return board[1][0] == 'X' ? 1 : 2;
  } else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] == board[2][0] && board[0][0] != '-') {
    return board[0][0] == 'X' ? 1 : 2;
  } else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] == board[2][1] && board[0][1] != '-') {
    return board[0][1] == 'X' ? 1 : 2;
  } else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] == board[2][2] && board[0][2] != '-') {
    return board[0][2] == 'X' ? 1 : 2;
  } else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == board[2][2] && board[0][0] != '-') {
    return board[0][0] == 'X' ? 1 : 2;
  } else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == board[2][0] && board[0][2] != '-') {
    return board[0][2] == 'X' ? 1 : 2;
  }
  return 0;
}

int ai(char board[3][3]) {
  return 0;
}

int main() {
  int players, i, j, plen1, plen2, turn, move, tie, found;
  char ch;
  plen1 = plen2 = -1;
  turn = tie = found = 0;

  for(i = 0; i < 3; i++) {
    for(j = 0; j < 3; j++) {
      board[i][j] = '-';
    }
  }

  printf("Enter the number of players(1/2): ");
  scanf("%d", &players);

  if(players == 2) {
    // reading player names
    printf("Enter the name of player 1: ");
    fgetc(stdin);
    i = 0;
    while((ch = fgetc(stdin)) != '\n') {
      names[0][i] = ch;
      i++;
    }
    plen1 = i;

    printf("Enter the name of player 2: ");
    i = 0;
    while((ch = fgetc(stdin)) != '\n') {
      names[1][i] = ch;
      i++;
    }
    plen2 = i;

    // simulating game
    while(win(board) == 0 && tie == 0) {
      move = -1;
      while(move < 1 || move > 9 || board[(move + (3 - move % 3) % 3) / 3 - 1][(move - 1) % 3] != '-') {
        if(move > -1) {
          printf("INVALID MOVE\n");
        }
        if(turn == 0) {
          for(i = 0; i < plen1; i++) {
            fputc(names[0][i], stdout);
          }
        } else {
          for(i = 0; i < plen2; i++) {
            fputc(names[1][i], stdout);
          }
        }
        printf(" moves: ");
        scanf("%d", &move);
      }
      board[(move + (3 - move % 3) % 3) / 3 - 1][(move - 1) % 3] = turn == 0 ? 'X' : '0';
      print_board();
      turn = 1 - turn;
      found = 0;
      // checking if it's a draw
      for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
          if(board[i][j] == '-') {
            found = 1;
          }
        }
      }
      if(found == 0) {
        tie = 1;
      }
    }

    // checking who won
    if(tie == 1) {
      printf("DRAW\n");
    } else {
      if(win(board) == 1) {
        for(i = 0; i < plen1; i++) {
          fputc(names[0][i], stdout);
        }
      } else if(win(board) == 2) {
        for(i = 0; i < plen2; i++) {
          fputc(names[1][i], stdout);
        }
      }
      printf(" WON\n");
    }
  } else {
    // reading player names
    printf("Enter your name: ");
    fgetc(stdin);
    i = 0;
    while((ch = fgetc(stdin)) != '\n') {
      names[0][i] = ch;
      i++;
    }
    plen1 = i;


  }

  return 0;
}
