#include <stdio.h>
#include <stdlib.h>

#define GAME_SIZE 200
#define TRUE 1
#define FALSE 0
#define TOTAL_ITERATIONS 1
#define BIRTH_THRESHOLD 89

void init_game_matrix(unsigned char game_matrix[GAME_SIZE][GAME_SIZE]) {
    unsigned char i, j, random_integer;
    srand(4);
    for (i = 0; i < GAME_SIZE; i++) {
        for (j = 0; j < GAME_SIZE; j++) {
            game_matrix[i][j] = FALSE;

            random_integer = rand() % 100;

            if (random_integer >= BIRTH_THRESHOLD) {
                game_matrix[i][j] = TRUE;
      }
    }
  }
}

void update_game_matrix(unsigned char game_matrix[GAME_SIZE][GAME_SIZE]) {
    unsigned char i, j, total_sum, random_coord_x, random_coord_y, random_integer;
    srand(4);
    for (i = 0; i < GAME_SIZE; i++) {
        for (j = 0; j < GAME_SIZE; j++) {
          unsigned char left_neighbour = FALSE;
          unsigned char right_neighbour = FALSE;
          unsigned char up_neighbour = FALSE;
          unsigned char down_neighbour = FALSE;
          unsigned char left_up_neighbour = FALSE;
          unsigned char right_up_neighbour = FALSE;
          unsigned char left_down_neighbour = FALSE;
          unsigned char right_down_neighbour = FALSE;

      if (i - 1 >= 0) {
        left_neighbour = game_matrix[i - 1][j];
      }
      if (i + 1 < GAME_SIZE) {
        right_neighbour = game_matrix[i + 1][j];
      }
      if (j - 1 >= 0) {
        down_neighbour = game_matrix[i][j - 1];
      }
      if (j + 1 < GAME_SIZE) {
        up_neighbour = game_matrix[i][j + 1];
      }

      if (i - 1 >= 0 && j - 1 >= 0) {
        left_down_neighbour = game_matrix[i - 1][j - 1];
      }
      if (i + 1 < GAME_SIZE && j - 1 >= 0) {
        right_down_neighbour = game_matrix[i + 1][j - 1];
      }
      if (i - 1 >= 0 && j + 1 < GAME_SIZE) {
        left_up_neighbour = game_matrix[i - 1][j + 1];
      }
      if (i + 1 < GAME_SIZE && j + 1 < GAME_SIZE) {
        right_up_neighbour = game_matrix[i + 1][j + 1];
      }

      total_sum = left_neighbour + right_neighbour + up_neighbour +
                      down_neighbour + left_down_neighbour + left_up_neighbour +
                      right_down_neighbour + right_up_neighbour;

      if (game_matrix[i][j]) {
        if (total_sum < 2 || total_sum > 3) {
          game_matrix[i][j] = FALSE;
        }
      } else {
        if (total_sum >= 3) {
          game_matrix[i][j] = TRUE;
        }
      }

      random_coord_x = rand() % GAME_SIZE;
      random_coord_y = rand() % GAME_SIZE;
      random_integer = rand() % 100;

      if (random_integer >= 19) {
        game_matrix[i][j] = game_matrix[random_coord_x][random_coord_y];
      }
    }
  }
}

int main() {
  unsigned char game_matrix[GAME_SIZE][GAME_SIZE];
    unsigned char i;

  init_game_matrix(game_matrix);

  for (i = 0; i < TOTAL_ITERATIONS; i++) {
    update_game_matrix(game_matrix);
  }
}