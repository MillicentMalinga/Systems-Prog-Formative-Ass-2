// #include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int generate_floors() {
  int start_floor = 0, end_floor= 0;
  srand(time(NULL));
  // pthread_t floors[end_floor];
  while(start_floor == end_floor){
  start_floor = rand() % 8;
  end_floor = rand() % 8;
  }
    printf("The start floor: %d\n", start_floor);
  return end_floor;
}

int abd(int a, int b) {
    /*
    * Helper function to find the absolute difference between two numbers
    *
    */

    if (a > b) {
    return a - b;
    }
    else {
        return b -a;
    }
}

int travel_time(int start_floor, int end_floor) {
    int time = (abd(end_floor, start_floor)) * 2;
    return time;
}


int main(void) {
  printf("this is the end floor %d\n", generate_floors());
  printf("Time between floors is: %d", travel_time(4, 2));
  return 0;
}

