#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

typedef struct Rider{
   int start, end, id;
}Rider;
#define THREAD_NUM 10
// static  struct Elevator{
//    int capacity;
//    int id;
//    int current_floor;  
//    Rider *rider;
// }Elevator;

  int waiters = 0;
    int waiting[20];
pthread_mutex_t elevatorMutex[2];

int currentFloor[2] = { 1, 1 };
int picked_up[10];
int capacity;

/* Function to collect people waiting for the elevator*/
void collectUsers(){
    printf("How many people are waiting for the elevators?\n");
    scanf("%d", &waiters);
    printf("Which floors are they waiting on?\n");
    for (int i = 0; i < waiters; i++){
        scanf("%d", &waiting[i]);
    }
}

// void *offload(Elevator *elevator){
//    int i;
//    for(i = 0; i < elevator->capacity; i++){
//       if(elevator->rider[i].end == elevator->current_floor){
//          printf("Rider %d offloaded at floor %d", elevator->rider[i].id, elevator->current_floor);}
//         elevator.capacity--;
// }
// }

/* Main elevator function */
void* travel(void* args) {
    int direction = 1;

    for (int i = 0; i < 2; i++) {
        if (pthread_mutex_trylock(&elevatorMutex[i]) == 0) { 
            while(1){
                
                printf("\nElevator %d current floor: %d\n\n", i+1, currentFloor[i]);
                for (int i = 0; i < waiters; i++){
                    if (waiting[i] == currentFloor[i] && capacity < 10){

                        printf("Rider %d is waiting on floor %d\n", i+1, currentFloor[i]);
                        printf("Picking up rider %d\n", i+1);
                        printf("Please enter your destination floor\n");
                        sleep(1);
                        scanf("%d", &picked_up[capacity]);
                        capacity++;
                        waiting[-1];
                        
                    }
                for (int i = 0; i < capacity; i++) {
                    if (picked_up[i] == currentFloor[i]) {
                        printf("Rider %d offloaded at floor %d\n", i+1, currentFloor[i]);
                        picked_up[-1];
                        capacity--;
                    }
                }
                }
                printf("-------------------------------------------------------\n");
        if (direction == 0){
        printf("\n----------------GOING DOWN------------------\n");
        }
        else if(direction == 1){
            printf("\n--------------- GOING UP------------------\n");
        }
          sleep(2);
            if (currentFloor[i] == 1 && currentFloor[i] != 8){
                direction = 1;
                currentFloor[i]++;
            }
           else if (currentFloor[i] < 8 && direction == 1){
                currentFloor[i]++;
            }
            else if (currentFloor[i] > 1 && currentFloor[i] == 8 || direction == 0){
                direction = 0;
            currentFloor[i]--;
            }
         
            }
            pthread_mutex_unlock(&elevatorMutex[i]);
        } else {
            if (i == 2) {
                i=0;
            }
        }
    }

}


int main(int argc, char* argv[]) {
    collectUsers();
    srand(time(NULL));
    pthread_t th[10];
    for (int i = 0; i < 2; i++) {
        pthread_mutex_init(&elevatorMutex[i], NULL);
    }
    for (int i = 0; i < 10; i++) {
        if (pthread_create(&th[i], NULL, &travel, NULL) != 0) {
            perror("Failed to create thread");
        }
    }
  
    for (int i = 0; i < 10; i++) {
     

        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    for (int i = 0; i < 2; i++) {
        pthread_mutex_destroy(&elevatorMutex[i]);
    }
    return 0;
}
