#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>


pthread_mutex_t elevatorMutex[2];
int currentFloor[2] = { 1, 1 };

void* travel(void* args) {
    int direction = 1;
   
    for (int i = 0; i < 2; i++) {
        if (pthread_mutex_trylock(&elevatorMutex[i]) == 0) {
            while(1){
                printf("\nElevator %d current floor: %d\n\n", i+1, currentFloor[i]);
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
