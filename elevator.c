#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int generate_floors() {
  int start_floor, end_floor;
  //seed time
  srand(time(NULL));
  // pthread_t floors[end_floor];
  while(start_floor == end_floor){
  start_floor = rand() % 8;
  end_floor = rand() % 8;
  }
    printf("The start floor: %d\n", start_floor);
  return end_floor;
}

// helper function for absolute difference
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


// calculate wait time for each thread

int travel_time(int start_floor, int end_floor){
 int travel_time = abd(end_floor, start_floor) * 2;
 return travel_time;

}


//Function to create threads
int create_thread(){
  int threads, num_threads = 5;
  //initializing mutex
  pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
  pthread_t thread[num_threads];
  sleep(2);
  for(int i=0; i < num_threads; i++){
    threads = pthread_create(&thread[num_threads], NULL, NULL, NULL);
  }

}



int main(void) {
  printf("this is the end floor %d", generate_floors());
  return 0;
}

