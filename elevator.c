#include <pthread.h>
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
// void *passenger_status(){
//     printf("Passenger called elevator.\n");

//   }

// // helper function for absolute difference
// int abd(int a, int b) {
//     /*
//     * Helper function to find the absolute difference between two numbers
//     *
//     */

//     if (a > b) {
//     return a - b;
//     }
//     else {
//         return b -a;
//     }
// }


// // calculate wait time for each thread

// int travel_time(int start_floor, int end_floor){
//  int travel_time = abd(end_floor, start_floor) * 2;
//  return travel_time;

// }



// void elevator_process(){
//   srand(time(NULL));
//   pthread_t passengers[5];
// int capacity = 5;
// int state = 0; // state of the elevator. 0 for idle and 1  for running
// int direction = 1; // direction the elevator is going in. 1 for up and -1 for down.
// int current_floor = 0; // the floors the elevator is in
// int final_destination = 0; // the final floor tht the elevator is going to. 
// int current_number = 0;  // number of people in the elevator.
// int passengers_in_waiting = rand() % 6;
// int available_space = capacity - current_number;
// int destination_floors[5];
// int times[5], threads;
// printf("You have %d passengers waiting\n", passengers_in_waiting);
// printf("The elevator has %d passengers\n", current_number);
// printf("The available space %d\n", available_space);

// if (passengers_in_waiting > available_space) {
//   printf("Only space for %d people\n", available_space);
// for (int i = 0; i < available_space; i++){
//    srand(time(NULL));
//  struct Floors floors = generate_floors();
//   int wait_time = travel_time(floors.start_floor, floors.end_floor);
//     threads = pthread_create(&passengers[i], NULL,&passenger_status, NULL);

//     if (threads != 0) {
//       printf("Something went wrong!");
//     }
//     pthread_join(&passengers[i], NULL);
//         printf("Your destination will be reached in %d\n", wait_time);

//   }
//   }
//   else if (passengers_in_waiting <= available_space) {
//     // printf("Welcome on board\n");
//     for (int i = 0; i < passengers_in_waiting; i++){
//        srand(time(NULL));
//  struct Floors floors = generate_floors();
//  printf("start: %d, end: %d", floors.start_floor, floors.end_floor);
//   int wait_time = travel_time(floors.start_floor, floors.end_floor);
//     threads = pthread_create(&passengers[i], NULL,&passenger_status, NULL);
//     if (threads != 0) {
//       printf("Something went wrong!");
//     }
//     pthread_join(&passengers[i], NULL);

//     printf("Your destination will be reached in %d\n", wait_time);
//   }

//   }
// }

// int request_elevator(int start_floor, int end_floor, int elevator_direction){
//   int passenger_direction, wait_time;
//   if (end_floor - start_floor < 0) {
//   passenger_direction = 0;
//   }
//   else if (end_floor - start_floor > 0){
//     passenger_direction =  1;
//   }
//   else {
//     printf("Destination invalid\n");
//   }

//   return wait_time;
// }


// int main(void) {
//       struct Floors floors = generate_floors();
    
//       elevator_process();
//   return 0;

//   }

 


// // // Function to create threads
// // int create_thread(){
// //   int threads, capacity = 5;
//   //initializing mutex
//   // pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
//   // pthread_t thread[capacity];
  