// #include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int request_elevator() {
  int start_floor, end_floor;
  srand(time(NULL));
  // pthread_t floors[end_floor];
  start_floor = rand() % 9;
  end_floor = rand() % 9;
    printf("The start floor: %d\n", start_floor);
  return end_floor;
}

int main(void) {
  printf("this is the end floor %d", request_elevator());
  return 0;
}