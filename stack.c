#include<stdio.h>
    #include<stdlib.h>
    #include<time.h>
    #include<pthread.h>
    #include<unistd.h>

    #define NUM_THREAD 2
    #define flr 7

    int current_floor;
    int dest_floor;
    int t,i;
    int df[flr];
    void *user();
    void *elevator();
    void Thread_creats();
    pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER; /*Mutex Initializer*/
 
    /*Elevator Operation*/

    void *elevator()
    {
        if(df[i]>current_floor)
        {
            printf("Direction ^\n");
            printf("   Up     |\n");
            while(current_floor!=df[i])
            {
                sleep(2);
                current_floor++;
                printf(" floor --> %d\n",current_floor);
            }
                printf("\n\n Door Open <--[ || ]-->\n\n");
                sleep(1);
                printf(" Passenger %d  Walks out....\n",t);
                sleep(1);
                printf("\n\n Door Close --> [|] <--\n\n");
        }
        else if(df[i]<current_floor)
        {
            printf(" Direction |\n");
            printf("   Down    V\n");
             while (df[i]!=current_floor)
            {
                sleep(1);
                current_floor--;
                printf(" floor --> %d\n", current_floor);
            }
            printf("\n\n Door Open <--[ || ]-->\n\n");
            sleep(1);
            printf(" Passenger %d Walks out....\n",t);
            sleep(1);
            printf("\n\n Door Close --> [|] <--\n\n");
        }
        else
        {
            sleep(1);
            printf(" You are at your destination floor...Please step out of the elevator\n\n");
            sleep(1);
            printf("\n\n Door Open <--[ || ]-->\n\n");
            sleep(1);
            printf(" Passenger %d Walks out....\n",t);
          sleep(1);
            printf("\n\n Door Close --> [|] <--\n\n");
        }   
    }


    void Thread_creats()
    {
        pthread_t thread[NUM_THREAD];
        int th;
            sleep(1);
            //printf("Creating Passenger %d \n",t);
            for(t=0;t<NUM_THREAD;t++)
            {
                th=pthread_create(&thread[NUM_THREAD],NULL,user,NULL);
                if(th)
                {
                    printf("ERROR Creating Thread\n");
                    exit(-1);
                }
            }
    }

    void *user()
    {
for (i=0;i<flr;i++)
        {   
            pthread_mutex_lock(&mymutex);
            /*Initialize Seed Time*/
            srand(time(NULL));
            dest_floor=rand()%flr; /*Generates a random Floor number*/
            sleep(1);
            df[i]=dest_floor;
            printf("Passenger %d Selects floor: %d\n",t,df[i]);
            pthread_mutex_unlock(&mymutex);
        }

            pthread_exit(NULL);
            return NULL;
    }

int main()
    {
        int el;   
        pthread_t elev1;
        //printf("Creating Elevator\n");
        el=pthread_create(&elev1,NULL, &elevator, NULL);
        if(el)
        {
            printf("ERROR Creating Thread\n");
            exit(-1);
        }
        Thread_creats(); /*Calls the function that creates all the threads*/

        return 0;
    }