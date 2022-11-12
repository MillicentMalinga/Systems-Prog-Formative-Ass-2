#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define MAX_PASSENGERS 5
#define MAX_FLOORS 8
int currentFloor;
int visit_floors[MAX_FLOORS];
int passengers[MAX_PASSENGERS];
int num;
int floors;
int passenger;
int numThreads = 10;
sem_t sem;


void *person(void *arg) {
    printf("Person %d enters the elevator to go to floor %d\n", passenger, floors);
    sem_wait(&sem); // wait for key
    //Give access to the next 7 threads into elevator
}
int RandomFloor() {
    srand(time(NULL));  // Initialization, should only be called once.
    int floors = rand() % 9; // Returns a pseudo-random integer between 0 and RAND_MAX.
    return floors;
}

 void *startThreads(void *arg) {

    pthread_t passengerT[numThreads];

    for (int i = 1; i < numThreads; ++i) {

        pthread_create(&passengerT[i], NULL, &person, (void *) &i);

        pthread_join(passengerT[i], NULL);

    }

    return 0;
}
void *elevator(void *arg)
{
    int i;
    while (1)
    {
        sem_wait(&sem);                                         // wait for passenger to arrive at floor and press button to call elevator
        printf("Elevator arrived at floor %d\n", currentFloor); // elevator arrives at floor
        for (i = 0; i < MAX_PASSENGERS; i++)
        { // check if any passengers are waiting on this floor
            if (passengers[i] == currentFloor)
            {                                                     // if passenger is waiting on this floor, let them in
                printf("Passenger %d entered the elevator\n", i); // passenger enters elevator
                passengers[i] = -1;                               // set passenger's destination to -1 so they don't get picked up again
            }
            else if (passengers[i] == -2)
            {                                                    // if passenger is in the elevator, drop them off at their destination
                printf("Passenger %d exited the elevator\n", i); // passenger exits elevator
                passengers[i] = -3;                              // set passenger's destination to -3 so they don't get dropped off again
            }
            else if (passengers[i] > currentFloor)
            {                                                     // if passenger is above current floor, pick them up
                printf("Passenger %d entered the elevator\n", i); // passenger enters elevator
                passengers[i] = -2;                               // set passenger's destination to -2 so they don't get picked up again
            }
            else if (passengers[i] == -3)
            { // if passenger has already exited the elevator, do nothing with them
            }
            else
            { // otherwise, do nothing with them
            }
        }
        sleep(2);
    }
    return NULL;
}
void *Passenger(void *arg)
{
    int id = *((int *)arg);
    int startFloor = rand() % MAX_FLOORS;
    int endFloor = rand() % MAX_FLOORS;
    while (startFloor == endFloor)
    {
        endFloor = rand() % MAX_FLOORS;
    }
    printf("Passenger %d waiting on floor %d\n", id, startFloor);
    passengers[id] = startFloor;
    sem_post(&sem);
    while (passengers[id] != -3)
    {
    }
    return NULL;
}
int main(int argc, char **argv)
{
    srand(time(NULL));
    pthread_t threads[MAX_PASSENGERS];
    sem_init(&sem, 0, 0);
    // int i;
    // for (i = 0; i < MAX_PASSENGERS; i++)
    // {
    //     pthread_create(&threads[i], NULL, &Passenger, &i);
    // }
     int i;
    for (i = 0; i < MAX_PASSENGERS; i++)
    {
        pthread_create(&threads[i], NULL, &Passenger, &i);
    }

    // int i;
    // pthread_t tid[numThreads]; // thread identifier
    // sem_init(&sem, 0, MAX_PASSENGERS); // initialize semaphore to 1: mutex
    // for (i = 0; i < numThreads; i++) { // create threads
    //     pthread_create(&tid[i], NULL, person, NULL); // and wait
    //     pthread_join(tid[i], NULL);  }


    pthread_t elevThread;
    pthread_t tid[numThreads]; // thread identifier
    pthread_create(&elevThread, NULL, &elevator, NULL);
    for (i = 0; i < MAX_PASSENGERS; i++)
    {
        pthread_create(&tid[i], NULL, person, NULL); // and wait
        pthread_join(tid[i], NULL);
        pthread_join(threads[i], NULL);
    }
    return EXIT_SUCCESS;
}

