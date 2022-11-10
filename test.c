#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

void *travelling(int arr[]){
pthread_mutex_lock(&lock);

	printf("\n Job %d has started\n", counter);
            sleep(2);
	printf("\n Job %d has finished\n", counter);

	pthread_mutex_unlock(&lock);

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

struct Floors {
    int start_floor, end_floor, travel_time;
};
void *travel(int n){

}

void elevator_simulator(){
    time_t t;
    int dest_floors[5];
    int num_passengers, available_space, final_destination=8, capacity=5;
    int direction = 1, state = 0, current_number=0, current_floor = 7;
    srand((unsigned) time(&t));
    struct Floors passengers[5];

// generating array of end floor
// for(int j = 0; j < 5; j++){
//     dest_floors[j] = (rand() % 8) + 1;

// }
    num_passengers = rand() % 6;
    if (num_passengers == 0) {
        printf("No passengers calling the elevator for now.\n");
    }
    printf("%d\n", num_passengers);
    for (int i = 0; i < num_passengers; i++){


        passengers[i].start_floor = current_floor;
        passengers[i].end_floor = (rand() % 8) +1;

        if (passengers[i].end_floor < current_floor) {
            passengers[i].travel_time = (final_destination * 2) + abd(passengers[i].end_floor, current_floor) * 2;

        }
        if (passengers[i].end_floor > current_floor ) {
            passengers[i].travel_time = (passengers[i].end_floor - current_floor) * 2;
        }

     
        printf("For passenger %d: start floor is %d and destination %d with %d travel time\n", i+1, passengers[i].start_floor, passengers[i].end_floor, passengers[i].travel_time);
    }


}


void main(){
    elevator_simulator();
}