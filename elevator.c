#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int request_elevator() {
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
  printf("this is the end floor %d", request_elevator());
  return 0;
}

