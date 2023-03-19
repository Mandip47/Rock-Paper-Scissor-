#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char choose[3] = {'R', 'P', 'S'};
char player;
char computer;
char retest;

void playerMove();
void computerMove();
void checkWinner();
void checkContinue();

int main(void) {
  printf("----Welcome to Game----\n");
  do {
    playerMove();
    computerMove();
    checkWinner();
    checkContinue();
  } while (retest == 'Y');

  printf("Thank you for Playing!! ");
  return 0;
}

void playerMove() {

  printf("\nchoose your move Rock(R),Paper(P)&scissor(S): ");
  scanf(" %c", &player);
  player = toupper(player);

  while (player != 'R' && player != 'P' && player != 'S') {
    printf("\nRe-try : ");
    scanf(" %c", &player);
    player = toupper(player);
  }
}

void computerMove() {
  srand(time(0));
  int i = rand() % 3;
  computer = choose[i];
}

void checkWinner() {
  if (player == computer) {
    printf("\nMatch Tied!!");
  } else if (player == choose[0] && computer == choose[1]) {
    printf("\nYou Lose!!");
  } else if (player == choose[0] && computer == choose[2]) {
    printf("\nYou Win!!");
  } else {
    printf("\nYou Lose!!");
  }
}

void checkContinue() {
  printf("\n\nDo you want to continue [Y/N] : ");
  scanf(" %c", &retest);
  retest = toupper(retest);
}
