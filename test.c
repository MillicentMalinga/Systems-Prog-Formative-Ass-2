#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>

/*
condition variables to manage the threads
*/
#define MAX_CAPACITY 5
pthread_cond_t avSpace; //to signal empty spaces. 
pthread_mutex_t elevatorLock;
int riders = 0;

/* the struct Rider holds information about the elevator riders. Their start is 
their starting floor, and end is the destination. wait_time is the time to travel from 
start to finish. ]
*/
typedef struct Rider{
   int start, end, wait_time, id;
}Rider;

Rider riderQueue[10]; // assumption that the building only hosts 10 people max. 


int abslute_diff(int a, int b) {
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

Rider load(Rider rider) {
    pthread_mutex_lock(&elevatorLock);
    riderQueue[riders] = rider;
    riders++;
    pthread_mutex_unlock(&elevatorLock);
    pthread_cond_signal(&avSpace); 
    return riderQueue[0];
}


void* transport(Rider*  rider) {
    if (rider->start > rider->end){
    rider->wait_time = 2* (16 - rider->start - rider->end);
    }
    else {
    rider->wait_time = 2* (rider->end - rider->start);
    }
    // for(int i = 0; i < rider->wait_time; i++){

        printf("\n Passenger %d is leaving floor %d for floor %d\n", rider->id, rider->start, rider->end);
        sleep(rider->wait_time);
        // if (rider->start < rider->end){
        // // printf("\nArriving on floor %d\n", rider->start++);
        // }
        // if (rider->start > rider->end){
        //             printf("\nArriving on floor %d\n", rider->start--);
        // }
    
    printf("\n Passenger %d has arrived on floor %d from floor %d\n", rider->id, rider->end, rider->start);
    return NULL;
}


void* travel(void* args) {
    while (1) {
        Rider rider;

        pthread_mutex_lock(&elevatorLock);
        while (riders == 0) {
            pthread_cond_wait(&avSpace, &elevatorLock);
        }

        rider = riderQueue[0];
        for (int i = 0; i < riders - 1; i++) {
            riderQueue[i] = riderQueue[i + 1];
        }
        riders--;
        pthread_mutex_unlock(&elevatorLock);
        transport(&rider);
        return NULL;
    }
}

int main(int argc, char* argv[]) {
    pthread_t th[MAX_CAPACITY];
    pthread_mutex_init(&elevatorLock, NULL);
    pthread_cond_init(&avSpace, NULL);
    int i;
    for (i = 0; i < MAX_CAPACITY; i++) {
        if (pthread_create(&th[i], NULL, &travel, NULL) != 0) {
            perror("Failed to load passenger");
        }
    }

    srand(time(NULL));
    for (i = 0; i < 5; i++) {
        Rider r = {
            .id = i + 1,
            .start = (rand() % 8) + 1,
            .end = (rand() % 8) + 1
        };
        load(r);
    }

    for (i = 0; i < MAX_CAPACITY; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to load passenger");
        }

    }
    pthread_mutex_destroy(&elevatorLock);
    pthread_cond_destroy(&avSpace);
    return 0;
}
