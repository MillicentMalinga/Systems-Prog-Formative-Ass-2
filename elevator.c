// #include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

struct Floors {
    int start_floor, end_floor;
};
struct Floors generate_floors() {
  struct Floors floors = {0, 0};
  //seed time
  srand(time(NULL));
  // pthread_t floors[end_floor];
  while(floors.start_floor == floors.end_floor){
  floors.start_floor = rand() % 8;
  floors.end_floor = rand() % 8;
  // }
  //   printf("The start floor: %d\n", start_floor);
  return floors;
}
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
// int create_thread(){
//   int threads, num_threads = 5;
//   //initializing mutex
//   pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
//   pthread_t thread[num_threads];
//   sleep(2);
//   for(int i=0; i < num_threads; i++){
//     threads = pthread_create(&thread[num_threads], NULL, NULL, NULL);
//   }

// }



int main(void) {
      struct Floors floors = generate_floors();
    printf("This is the starting floor %d\n", floors.start_floor);
        printf("This is the destination floor %d\n", floors.end_floor);
        printf("The travel time will be: %d", travel_time(floors.start_floor, floors.end_floor));
  return 0;

  }

